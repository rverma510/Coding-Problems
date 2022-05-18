// https://leetcode.com/problems/reverse-words-in-a-string

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    vector<string> res;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' && tmp.size() > 0) {
            res.push_back(tmp);
            tmp = "";
        }
        else if (s[i] != ' ') {
            tmp += s[i];
        }
    }
    if (tmp.size() > 0) {
        res.push_back(tmp);
    }
    string ans = "";
    for (int i = res.size() - 1; i > 0; i--) {
        ans += res[i] + ' ';
    }
    ans += res[0];
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s) << '\n';
}