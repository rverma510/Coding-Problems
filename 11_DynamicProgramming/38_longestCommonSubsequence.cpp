#include <bits/stdc++.h>
using namespace std;
int recursiveLCS(string str1, string str2, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (str1[m - 1] == str2[n - 1])
        return 1 + recursiveLCS(str1, str2, m - 1, n - 1);
    else
        return max(
            recursiveLCS(str1, str2, m - 1, n), 
            max(
                recursiveLCS(str1, str2, m, n - 1),
                recursiveLCS(str1, str2, m - 1, n - 1)
                )
            );
}

int dynamicLCS(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }
    return dp[m][n];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    // cout << recursiveLCS(str1, str2, str1.size(), str2.size()) << endl;
    cout << dynamicLCS(str1, str2) << endl;
    return 0;
}