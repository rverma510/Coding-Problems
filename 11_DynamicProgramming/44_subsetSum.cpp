#include <iostream>
#include <vector>
using namespace std;

bool dynamicSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    } 
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[n][sum];
}

int main() {
    int n, sum;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> sum;
    cout << dynamicSubsetSum(arr, sum) << endl;
    return 0;
}