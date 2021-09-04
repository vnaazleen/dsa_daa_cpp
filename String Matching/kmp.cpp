#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPSArray(string pattern) {
    vector<int> lps(pattern.size());
    int len = 0;
    int i = 1;

    lps[0] = 0;

    while(i < pattern.size()) {
        if(pattern[len] == pattern[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    cout << "Prefix array: " << endl;
    for(int i = 0; i < pattern.size(); i++) {
        cout << lps[i] << " ";
    } cout << endl;

    return lps;
}

int kmp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> lps = computeLPSArray(pattern);

    int i = 0;
    int j = 0;
    while(i < n) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        } 

        if(j == m) {
            return i - m;
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return -1;
}

int main() {
    // Time complexity: O(n) | Space: O(m) where m = len of pattern, n = len of text
    string text;
    string pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    int index = kmp(text, pattern);
    if(index == -1) {
        cout << "Pattern not found!" << endl;
    } else {
        cout << "Pattern found at index " << index << endl;
    }
}
