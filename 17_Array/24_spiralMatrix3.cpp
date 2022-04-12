// https://leetcode.com/problems/spiral-matrix-ii/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    int startRow = 0, endRow = n - 1;
    int startCol = 0, endCol = n - 1;
    int cnt = 1;
    while (cnt <= n * n) {
        for (int i = startCol; i <= endCol; i++) {
            if (cnt > n * n) break;
            res[startRow][i] = cnt;
            cnt++;
        }
        startRow++;
        for (int i = startRow; i <= endRow; i++) {
            if (cnt > n * n) break;
            res[i][endCol] = cnt;
            cnt++;
        }
        endCol--;
        for (int i = endCol; i >= startCol; i--) {
            if (cnt > n * n) break;
            res[endRow][i] = cnt;
            cnt++;
        }
        endRow--;
        for (int i = endRow; i >= startRow; i--) {
            if (cnt > n * n) break;
            res[i][startCol] = cnt;
            cnt++;
        }
        startCol++;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> res = generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}