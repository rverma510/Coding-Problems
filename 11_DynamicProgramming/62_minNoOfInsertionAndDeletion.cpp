#include <bits/stdc++.h>
using namespace std;

int minInsAndDel(string x, string y) {
    int m = x.size();
    int n = y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

void printMinInsAndDel(string x, string y) {
    int m = x.size();
    int n = y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << "Min Deletion  : " << (m - dp[m][n]) << endl;
    cout << "Min Insertion : " << (n - dp[m][n]) << endl;
}

int main() {
    string x, y;
    cin >> x >> y;
    // cout << minInsAndDel(x, y) << endl;
    printMinInsAndDel(x, y);
    return 0;
}