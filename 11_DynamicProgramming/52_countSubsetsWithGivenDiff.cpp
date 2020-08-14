#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> &arr, int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else 
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main () {
    int n, sum = 0, diff;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> diff;
    cout << countSubsets(arr, n, (sum + diff) / 2) << endl;
    return 0;
}