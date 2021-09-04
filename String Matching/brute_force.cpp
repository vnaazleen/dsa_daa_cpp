#include <iostream>

using namespace std;

int brute_force(string text, string pattern) {
    for(int i = 0; i < text.size() - pattern.size(); i++) {
        int match = 0;
        int k = i;
        for(int j = 0; j < pattern.size(); j++) {
            if(pattern[j] == text[k++]) {
                match++;
            }
        }

        if(match == pattern.size()) { return i;}
    }

    return -1;
}

int main() {
    // Time complexity: O(m * n) | Space: O(1), where m = len of text, n = len of pattern
    string text;
    string pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    int index = brute_force(text, pattern);
    if(index == -1) {
        cout << "Pattern not found!" << endl;
    } else {
        cout << "Pattern found at index " << index << endl;
    }
}
