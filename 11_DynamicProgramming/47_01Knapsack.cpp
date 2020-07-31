#include <bits/stdc++.h>
using namespace std;

int recursiveKnapsack(int n, vector<int> &weight, vector<int> &value, int W) {
    if (n == 0 || W == 0)
        return 0;
    if (W < weight[n - 1])
        return recursiveKnapsack(n - 1, weight, value, W);
    return max(
        value[n - 1] + recursiveKnapsack(n - 1, weight, value, W - weight[n - 1]),
        recursiveKnapsack(n - 1, weight, value, W)
    );
}

int dynamicKnapsack(int n, vector<int> weight, vector<int> &value, int W) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= W; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i - 1]){
                dp[i][j] = max(dp[i][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cin >> n;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    cin >> W;
    // cout << recursiveKnapsack(n, weight, value, W) << endl;
    cout << dynamicKnapsack(n, weight, value, W) << endl;
    return 0;
}

/*

3
10 20 30
60 100 120
50

*/