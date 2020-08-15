#include <bits/stdc++.h>
using namespace std;

int dynamicRodProfit(vector<int> &p, vector<int> &prof, int n, int len) {
    vector<vector<int>> dp(n + 1, vector<int>(len + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= len; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (p[i - 1] <= j) 
                dp[i][j] = max(prof[i - 1] + dp[i][j - p[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][len];
}

int main() {
    int n, len;
    cin >> n;
    vector<int> p(n), prof(n);
    for (int i = 0; i < n; i++) 
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> prof[i];
    cin >> len;
    cout << dynamicRodProfit(p, prof, n, len) << endl;
    return 0;
}