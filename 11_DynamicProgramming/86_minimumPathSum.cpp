// https://leetcode.com/problems/minimum-path-sum/

#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<int>> &dp) {
    if (i == n - 1 && j == m - 1) {
        return grid[i][j];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans1 = INT_MAX, ans2 = INT_MAX;
    if (i + 1 < n) {
        ans1 = helper(grid, i + 1, j, n, m, dp);
    }
    if (j + 1 < m) {
        ans2 = helper(grid, i, j + 1, n, m, dp);
    }
    return dp[i][j] = grid[i][j] + min(ans1, ans2);
}

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(grid, 0, 0, n, m, dp);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << minPathSum(grid) << '\n';
    return 0;
}