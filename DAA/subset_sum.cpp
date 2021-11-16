#include <iostream>
#include <vector>

using namespace std;

int count;

void printSolution(vector<int> arr, vector<int> solution, int n) {
    count++;
    cout << "Solution " << count << ": ";
    for(int i = 0; i < n; i++) {
        cout << solution[i] << " ";
    }  cout << endl;
    
    cout << "Elements of the set are: ";
    for(int i = 0; i < n; i++) {
        if (solution[i])
            cout << arr[i] << " ";
    }  cout << endl;
}

void findSubset(vector<int> arr, vector<int> solution, int k, int curSum, int i, int n) {
    if(i >= n || curSum >= k) {
        if(curSum == k)
            printSolution(arr, solution, n);
        return;
    }
    
    findSubset(arr, solution, k, curSum, i + 1, n);
    solution[i] = 1;
    findSubset(arr, solution, k, curSum + arr[i], i + 1, n);
}

int main() {
    int n;
    cout << "Enter no of elements in the subset: ";
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int k;
    cout << "Enter sum: ";
    cin >> k;
    
    vector<int> solution(n, 0);
    count = 0;
    
    findSubset(arr, solution, k, 0, 0, n);

    return 0;
}
