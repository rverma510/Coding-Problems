#include <iostream>
#include <vector>
using namespace std;

int recursiveEdit(string str1, string str2, int m, int n) {
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (str1[m - 1] == str2[n - 1])
        return recursiveEdit(str1, str2, m - 1, n - 1);
    else
        return 1 + min(
            recursiveEdit(str1, str2, m - 1, n), min(
                recursiveEdit(str1, str2, m, n - 1),
                recursiveEdit(str1, str2, m - 1, n - 1)
            )
        );
}

int dynamicEdit(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        dp[i][0] = i;
    for (int i = 1; i <= n; i++)
        dp[0][i] = i;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }
    return dp[m][n];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    // cout << recursiveEdit(str1, str2, str1.size(), str2.size()) << endl;
    cout << dynamicEdit(str1, str2) << endl;
    return 0;
}