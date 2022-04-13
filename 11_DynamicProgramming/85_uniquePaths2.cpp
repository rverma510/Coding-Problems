

#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &obstacleGrid, int i, int j, int n, int m, vector<vector<int>> &dp) {
    if (i == n - 1 && j == m - 1){
        if (obstacleGrid[i][j] == 0) return 1;
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (j + 1 < m && obstacleGrid[i][j] == 0) {
        ans += helper(obstacleGrid, i, j + 1, n, m, dp);
    }
    if (i + 1 < n && obstacleGrid[i][j] == 0) {
        ans += helper(obstacleGrid, i + 1, j, n, m, dp);
    }
    return dp[i][j] = ans;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(obstacleGrid, 0, 0, n, m, dp);
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
    cout << uniquePathsWithObstacles(grid) << '\n';
    return 0;
}