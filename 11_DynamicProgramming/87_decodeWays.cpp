// https://leetcode.com/problems/decode-ways

#include <bits/stdc++.h>
using namespace std;

int helper(string s, int i, vector<int> &dp) {
    int n = s.size();
    if (i == n) return 1;
    if (dp[i] != -1) return dp[i];
    if (s[i] == '0') return 0;
    dp[i] = helper(s, i + 1, dp);
    if (i < n - 1 && ((s[i] == '1') || (s[i] == '2' && s[i + 1] < '7'))) {
        dp[i] += helper(s, i + 2, dp);
    }
    return dp[i];
}
int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return helper(s, 0, dp);
}

int main() {
    string s;
    cin >> s;
    cout << numDecodings(s) << '\n';
    return 0;
}