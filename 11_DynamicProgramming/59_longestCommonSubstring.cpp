#include <bits/stdc++.h>
using namespace std;

int dynamicLCSubstring(string x, string y) {
    int m = x.size();
    int n = y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int mx = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
            mx = max(mx, dp[i][j]);
        }
    }
    return mx;
}

int main() {
    string x, y;
    cin >> x >> y;
    cout << dynamicLCSubstring(x, y) << endl;
    return 0;
}