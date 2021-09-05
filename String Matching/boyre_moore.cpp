#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define TOTAL_CHAR 256

void fillBadMatchTable(string pattern, vector<int>& bmt) {
    for(int i = 0; i < pattern.size(); i++) {
        bmt[(int)pattern[i]] = i;
    }
}

void boyre_moore(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();

    vector<int> bad_match_table(TOTAL_CHAR, 0);
    fillBadMatchTable(pattern, bad_match_table);

    int shift = 0;
    while(shift <= (n - m)) {
        int j = m - 1;
        while(j >= 0 && pattern[j] == text[shift + j]) 
            j--;
        
        if(j < 0) {
            cout << "Pattern found at: " << shift << endl; 
            return;
        } else {
            shift += max(1, j - bad_match_table[text[shift + j]]);
        }
    }
}

int main() {
    string text;
    getline(cin, text);

    string pattern;
    getline(cin, pattern);

    boyre_moore(text, pattern);
    return 0;
}
