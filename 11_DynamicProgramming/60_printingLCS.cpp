#include <bits/stdc++.h>
using namespace std;

void printLCS(string x, string y) {
    int m = x.size();
    int n = y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int i, j;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string res = "";
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            res = res + x[i - 1];
            i--; j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main() {
    string x, y;
    cin >> x >> y;
    printLCS(x, y);
    return 0;
}