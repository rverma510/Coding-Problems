#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> &arr, int n, int sum) {
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] | dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum & 1)
        cout << 0 << endl;
    else
        cout << subsetSum(arr, n, sum / 2) << endl;
    return 0;

}