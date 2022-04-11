// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    map<string, vector<string>> mp;
    for (int i = 0; i < strs.size(); i++) {
        string s = strs[i];
        sort(s.begin(), s.end());
        mp[s].push_back(strs[i]);
    }
    for (auto i: mp) {
        res.push_back(i.second);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    vector<vector<string>> res = groupAnagrams(strs);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
/*
6
eat tea tan ate nat bat
*/