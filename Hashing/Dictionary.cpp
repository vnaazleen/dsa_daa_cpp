#include <iostream>
#include <cstring>

using namespace std;

// Basic Hash table implementataion without any collision handling techniuques 
// Key : Word (String), Value: meaning (String)

class Dictionary {
    private:
        static const int hashGroups = 10;
        pair<string, string> dict[hashGroups];
        int size = 0;
    
    public:
        bool isEmpty();
        int hashFunction(string key);
        void insertItem(string key, string value);
        void removeItem(string key);
        string searchItem(string key);
        void printDict();
};

bool Dictionary::isEmpty() {
    return size == 0;
}

int Dictionary::hashFunction(string key) {
    int ascii_sum = 0;
    for (int i = 0; i < key.length(); i++) {
        ascii_sum += (key[i] - 'a');
    }
    return ascii_sum % hashGroups;
}

void Dictionary::insertItem(string key, string value) {
    int hashValue = hashFunction(key);
    if (dict[hashValue].first != key) {
        dict[hashValue] = make_pair(key, value);
        size++;
    } else {
        dict[hashValue].second = value;
    }
}

void Dictionary::removeItem(string key) {
    int hashValue = hashFunction(key);
    if (dict[hashValue].first != key) {
        cout << "Key not found" << endl;
    } else {
        dict[hashValue].first =  "";
        dict[hashValue].second = "";
        size--;
    }
}

string Dictionary::searchItem(string key) {
    int hashValue = hashFunction(key);
    if (dict[hashValue].first != key) {
        return "Key not found";
    } 
    return dict[hashValue].second;

}

void Dictionary::printDict() {
    for (int i = 0; i < hashGroups; i++) {
        if (dict[i].first == "") {
            continue;
        }
        cout << dict[i].first << " " << dict[i].second << endl;
    }
}

int main() {
    Dictionary d; 

    if(d.isEmpty()) cout << "Dictionary is empty!"<< endl;
    else cout << "Dictionary is not empty!"<< endl;

    d.insertItem("abc", "a..b..c..");
    d.insertItem("bcd", "b..c..d..");
    d.insertItem("efg", "e..f..g..");
    d.insertItem("xyz", "x..y..z..");

    cout << "=====================" << endl;
    d.printDict();
    cout << "=====================" << endl;

    d.insertItem("abc", "c..b..a..");
    d.removeItem("bcd");

    cout << d.searchItem("efg") << endl;
    cout << d.searchItem("pqr") << endl;

    if(d.isEmpty()) cout << "Dictionary is empty!"<< endl;
    else cout << "Dictionary is not empty!"<< endl;
    
    cout << "=====================" << endl;
    d.printDict();
    cout << "=====================" << endl;
}
