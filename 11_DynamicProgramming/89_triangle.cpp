// https://leetcode.com/problems/triangle

#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp) {
    if (i == n - 1) {
        return triangle[i][j];
    }
    if (dp[i][j] != -1) return dp[i][j];
    int ans = min(helper(triangle, i + 1, j, n, dp), helper(triangle, i + 1, j + 1, n, dp));
    return dp[i][j] = triangle[i][j] + ans;
}
int minimumTotal(vector<vector<int>>& triangle) {
    // int n = triangle.size();
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return helper(triangle, 0, 0, n, dp);
    int n = triangle.size();
    vector<vector<int>> dp(2, vector<int>(n, -1));
    dp[0][0] = triangle[0][0];
    bool pos = true;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[pos][j] = triangle[i][j] + dp[!pos][j];
            }
            else if (j == i) {
                dp[pos][j] = triangle[i][j] + dp[!pos][j - 1];
            }
            else {
                dp[pos][j] = triangle[i][j] + min(dp[!pos][j - 1], dp[!pos][j]);
            }
        }
        pos = !pos;
    }
    int ans = INT_MAX;
    pos = !pos;
    for  (int i = 0; i < n; i++) {
        ans = min(ans, dp[pos][i]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        vector<int> t(i + 1);
        for (int j = 0; j < i + 1; j++) {
            cin >> t[j];
        }
        triangle[i] = t;
    }
    cout << minimumTotal(triangle) << '\n';
    return 0;
}

/*

4
2
3 4
6 5 7
4 1 8 3

*/