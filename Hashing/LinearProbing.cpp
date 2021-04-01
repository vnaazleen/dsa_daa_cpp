#include <iostream>
#include <cstring>

using namespace std;

// Hash table implementataion with Linear probing
// Key : Word (String), Value: meaning (String)

class Dictionary {
    private:
        static const int hashGroups = 10;
        pair<string, string> dict[hashGroups];
        int size = 0;
    
    public:
        bool isEmpty();
        int hashFunction(string key, int i);
        void insertItem(string key, string value);
        void removeItem(string key);
        string searchItem(string key);
        void printDict();
};

bool Dictionary::isEmpty() {
    return size == 0;
}

int Dictionary::hashFunction(string key, int i) {
    int ascii_sum = 0;
    for (int i = 0; i < key.length(); i++) {
        ascii_sum += (key[i] - 'a');
    }
    return (ascii_sum + i) % hashGroups;
}

void Dictionary::insertItem(string key, string value) {
    int i = 0;
    do {
        int hashValue = hashFunction(key, i++);
        if (dict[hashValue].first == key) {
            dict[hashValue].second = value;
            return;
        } else if (dict[hashValue].first == "") {
            dict[hashValue] = make_pair(key, value);
            return;
        } 
    } while (i < hashGroups);
}

void Dictionary::removeItem(string key) {
    int i = 0;
    do {
        int hashValue = hashFunction(key, i++);
        if (dict[hashValue].first == key) {
            dict[hashValue].first =  "";
            dict[hashValue].second = "";
            size--;
            return;
        }
    } while (i < hashGroups);

    cout << "Key not found" << endl;
}

string Dictionary::searchItem(string key) {
    int i = 0;
    do {
        int hashValue = hashFunction(key, i++);
        if (dict[hashValue].first == key) {
            return dict[hashValue].second;
        }
    } while (i < hashGroups);

    return "Key not found";

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
    d.insertItem("bd", "b..d.."); // occurs collision with abc

    cout << "=====================" << endl;
    d.printDict();
    cout << "=====================" << endl; 

    d.removeItem("bcd");
    cout << d.searchItem("efg") << endl;
    cout << d.searchItem("pqr") << endl;

    if(d.isEmpty()) cout << "Dictionary is empty!"<< endl;
    else cout << "Dictionary is not empty!"<< endl;
    
    cout << "=====================" << endl;
    d.printDict();
    cout << "=====================" << endl;
}
