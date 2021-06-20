#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[1000][1000];

int kInversePairs(int n, int k) {
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            if (j - i >= 0) {
                dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
            }
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << kInversePairs(n, k) << '\n';
    return 0;
}