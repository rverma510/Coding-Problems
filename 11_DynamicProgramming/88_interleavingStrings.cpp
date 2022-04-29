// https://leetcode.com/problems/interleaving-string

#include <bits/stdc++.h>
using namespace std;

bool helper(string s1, int n, string s2, int m, string s3, vector<vector<int>> &dp) {
    if (n == 0) {
        return !(s2.substr(0, m).compare(s3.substr(0, m)));
    }
    if (m == 0) {
        return !(s1.substr(0, n).compare(s3.substr(0, n)));
    }
    if (dp[n][m] != -1) return dp[n][m];
    bool ans = false;
    if ((s1[n - 1] == s3[n + m - 1] && helper(s1, n - 1, s2, m, s3, dp)) ||
        (s2[m - 1] == s3[n + m - 1] && helper(s1, n, s2, m - 1, s3, dp))) {
        ans = true;
    }
    return dp[n][m] = ans;
}
bool isInterleave(string s1, string s2, string s3) {
    int n = s1.length();
    int m = s2.length();
    int l = s3.length();
    if (l != n + m) {
        return false;
    }
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // return helper(s1, n, s2, m, s3, dp);
    
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = !(s1.substr(0, i).compare(s3.substr(0, i)));
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = !(s2.substr(0, j).compare(s3.substr(0, j)));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || 
                (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1])) {
                dp[i][j] = true;
            }
        }
    }
    return dp[n][m];   
}




int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << isInterleave(s1, s2, s3) << '\n';
    return 0;
}

/*

b
b

aabcc
dbbca
aadbbcbcac

*/

