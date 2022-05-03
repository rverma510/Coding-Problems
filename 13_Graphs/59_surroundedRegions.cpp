// https://leetcode.com/problems/surrounded-regions

#include <bits/stdc++.h>
using namespace std;

void dfs (vector<vector<char>> &board, int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;
    board[i][j] = '-';
    dfs(board, i + 1, j, m, n);
    dfs(board, i - 1, j, m, n);
    dfs(board, i, j + 1, m, n);
    dfs(board, i, j - 1, m, n);
}
void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    
    for (int i = 0; i < m; i++) {
        dfs(board, i, 0, m, n);
        dfs(board, i, n - 1, m, n);
    }
    
    for (int j = 1; j < n - 1; j++) {
        dfs(board, 0, j, m, n);
        dfs(board, m - 1, j, m, n);
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '-') {
                board[i][j] = 'O';
            }
        }
    }
    
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    solve(board);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/*

4 4
XXXX
XOOX
XXOX
XOXX

*/