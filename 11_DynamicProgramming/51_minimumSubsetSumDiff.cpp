#include <bits/stdc++.h>
using namespace std;

int minSubsetsDiff(vector<int> &arr, int n, int sum) {
    vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum / 2; j++) {
            if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int diff = INT_MAX;
    for (int i = 0; i <= sum / 2; i++) {
        if (dp[n][i]) {
            diff = min(diff, sum - 2 * i);
        }
    }
    return diff;
}

int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << minSubsetsDiff(arr, n, sum) << endl;
    return 0;
}