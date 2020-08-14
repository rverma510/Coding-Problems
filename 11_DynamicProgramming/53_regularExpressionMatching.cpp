#include <bits/stdc++.h>
using namespace std;

bool recursiveMatching(string s, int i, string p, int j) {
    if (j == p.size()) return i == s.size();
    
    bool isCurrentMatching = i != s.size() && (s[i] == p[j] || p[j] == '.');

    if (j + 1 < p.size() && p[j + 1] == '*') {
        return (isCurrentMatching && recursiveMatching(s, i + 1, p, j)) || 
                recursiveMatching(s, i, p, j + 2);
    }
    else {
        return recursiveMatching(s, i + 1, p, j + 1);
    }
}

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*')
            dp[0][i] = dp[0][i - 2];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (p[j - 2] == '.' || s[i - 1] == p[j - 2])
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s, p;
    getline(cin, s);
    getline(cin, p);
    cout << isMatch(s, p) << endl;
    return 0;
}