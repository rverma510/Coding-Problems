//  https://leetcode.com/problems/word-break

#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st;
    int mx = INT_MIN;
    for (int i = 0; i < wordDict.size(); i++) {
        st.insert(wordDict[i]);
        mx = max(mx, (int)wordDict[i].length());
    }
    vector<bool> dp(s.length() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.length(); i++) {
        for (int j = i - 1; j >= max(i - mx, 0); j--) {
            if (dp[j]) {
                string word = s.substr(j, i - j);
                if (st.find(word) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.length()];
}

int main() {
    string s;
    cin >> s;
    int n; cin >> n;
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }
    cout << wordBreak(s, wordDict) << '\n';
    return 0;
}