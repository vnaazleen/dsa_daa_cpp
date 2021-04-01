#include <iostream>
#include <list>
#include <cstring>

using namespace std;

// Basic Hash table implementataion with separate chaining
// Key : Word (String), Value: meaning (String)

class Dictionary {
    private:
        static const int hashGroups = 10;
        list<pair<string, string>> dict[hashGroups];
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
    int total_elem = 0;
    for (int i = 0; i < hashGroups; i++) {
        total_elem += dict[i].size();  
    }

    return total_elem == 0;
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
    auto &cell = dict[hashValue];
    auto itr = begin(cell);
    bool keyExists = false;
    for (; itr != end(cell); itr++) {
        if (itr -> first == key) {
            keyExists = true;
            itr -> second = value;
            break;
        }
    }

    if(!keyExists) {
        cell.emplace_back(key, value);
    }
}

void Dictionary::removeItem(string key) {
    int hashValue = hashFunction(key);
    auto &cell = dict[hashValue];
    auto itr = begin(cell);
    bool keyExists = false;
    for (; itr != end(cell); itr++) {
        if (itr -> first == key) {
            keyExists = true;
            itr = cell.erase(itr);
            break;
        }
    }

    if(!keyExists) {
        cout << "[WARNING] Key not found" << endl;
    }
}

string Dictionary::searchItem(string key) {
    int hashValue = hashFunction(key);
    auto &cell = dict[hashValue];
    auto itr = begin(cell);
    bool keyExists = false;
    for (; itr != end(cell); itr++) {
        if (itr -> first == key) {
            keyExists = true;
            return itr -> second;
        }
    }

    if(!keyExists) {
        return "[WARNING] Key not found";
    }
}

void Dictionary::printDict() {
    for (int i = 0; i < hashGroups; i++) {
        if(dict[i].size() == 0) { continue; }

        auto itr = dict[i].begin();
        for(; itr != dict[i].end(); itr++) {
            cout << "Key: " << itr -> first << " Value: " << itr -> second << endl;
        }
    }
}

int main() {
    Dictionary d;
    d.insertItem("abc", "a..b..c..");
    d.insertItem("bcd", "b..c..d..");
    d.insertItem("efg", "e..f..g..");
    d.insertItem("xyz", "x..y..z..");
    d.printDict();
    cout << "=====================" << endl;
    d.insertItem("abc", "c..b..a..");
    d.removeItem("bcd");
    cout << d.searchItem("efg") << endl;
    cout << d.searchItem("def") << endl;  // [WARNING] Key not found
    
    d.printDict();
}
