/**
 * @file anagram.cpp
 * @author Vaseem Naazleen Shaik
 * @brief
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */

/*
Two words are anagrams of one another if their letters can be rearranged to form
the other word.

Given a string, split it into two contiguous substrings of equal length.
Determine the minimum number of characters to change to make the two substrings
into anagrams of one another.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
  int n = s.length();

  // given string has odd length then it cannot be divided into 2 parts
  if (n % 2 == 1) {
    return -1;
  }

  vector<int> f1(26, 0);
  for (int i = 0; i < n / 2; i++) {
    f1[s[i] - 'a']++;
  }

  vector<int> f2(26, 0);
  for (int i = n / 2; i < n; i++) {
    f2[s[i] - 'a']++;
  }

  int ans = 0;
  for (int i = 0; i < 26; i++) {
    ans += abs(f1[i] - f2[i]);
  }
  return ans / 2;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string q_temp;
  getline(cin, q_temp);

  int q = stoi(ltrim(rtrim(q_temp)));

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string s;
    getline(cin, s);

    int result = anagram(s);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
