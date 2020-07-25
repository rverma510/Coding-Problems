#include <iostream>
#include <vector>
using namespace std;

int dynamicPathHelper(vector<vector<int>> &v, int i, int j, int n, vector<vector<int>> &dp) {
    if (i < 0 || i >= n || j < 0 || j >= n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int x = -1, y = -1, z = -1, w = -1;
    if (j < n - 1 && v[i][j] + 1 == v[i][j + 1])
        x = 1 + dynamicPathHelper(v, i, j + 1, n, dp);
    if (j > 0 && v[i][j] + 1 == v[i][j - 1])
        y = 1 + dynamicPathHelper(v, i, j - 1, n , dp);
    if (i < n - 1 && v[i][j] + 1 == v[i + 1][j])
        z = 1 + dynamicPathHelper(v, i + 1, j, n, dp);
    if (i > 0 && v[i][j] + 1 == v[i - 1][j])
        w = 1 + dynamicPathHelper(v, i - 1, j, n, dp);
    return dp[i][j] = max(x, max(y, max(z, max(w, 1))));
}

int dynamicPath(vector<vector<int>> &v) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1)
                dp[i][j] = dynamicPathHelper(v, i, j, n, dp);
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    cout << dynamicPath(v) << endl;
    return 0;
}

/*

3
1 2 9 5 3 8 4 6 7

*/