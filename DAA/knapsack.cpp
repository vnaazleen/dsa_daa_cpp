#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
public:
    int id;
    int weight;
    int value;
    
    Item(int i, int wt, int val) {
        this -> id = i;
        this -> weight = wt;
        this -> value = val;
    }
};

bool compare(Item* a, Item* b) {
    int pw_ratio_a = (double)a -> value / a -> weight;
    int pw_ratio_b = (double)b -> value / b -> weight;
    
    return pw_ratio_a > pw_ratio_b;
}

int main()
{
    int capacity;
    cin >> capacity;
    
    int n; // no of items in the knapsack
    cin >> n;
    
    vector<Item*> items;
    for(int i = 0; i < n; i++) {
        int wt, val;
        cout << "Enter weight and profit of " << i + 1 << "th elemet: ";
        cin >> wt >> val;
        
        Item* item = new Item(i, wt, val);
        items.push_back(item);
    }
    
    sort(items.begin(), items.end(), compare);
    
    vector<double> solution(n, 0);
    double total_profit = 0;
    for(int i = 0; i < n; i++) {
        Item* item = items[i];
        if(capacity - item -> weight >= 0) {
            capacity -= item -> weight;
            solution[item->id] = 1;
            total_profit += item -> value;
        } else {
            solution[item->id] = (double)capacity / item -> weight;
            total_profit += item -> value * solution[item->id];
            capacity = 0;
        }
        
        if(capacity <= 0) {
            break;        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << solution[i] << " ";
    } cout << endl;
    cout << "Total profit: " << total_profit << endl;
                                                                                                       
    return 0;
}
