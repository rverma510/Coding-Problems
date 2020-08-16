// minimum no. of coins
#include <bits/stdc++.h>
using namespace std;

int dynamicCoins(vector<int> &coins, int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0) {
                dp[i][j] = 0;
            }
            else if (i == 0) {
                dp[i][j] = INT_MAX;
            }
            else {
                dp[i][j] = dp[i - 1][j];
                if (coins[i - 1] <= j && dp[i][j - coins[i - 1]] != INT_MAX && dp[i][j - coins[i - 1]] + 1 < dp[i][j])
                    dp[i][j] = dp[i][j - coins[i - 1]] + 1;
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int n, sum;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cin >> sum;
    cout << dynamicCoins(coins, n, sum) << endl;
    return 0;
}