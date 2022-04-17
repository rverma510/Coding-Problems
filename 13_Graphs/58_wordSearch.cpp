// https://leetcode.com/problems/word-search/

#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool existHelper(vector<vector<char>> &board, int i, int j, int n, int m, string word, int s) {
    if (s == 0) {
        return true;
    }
    for (int k = 0; k < 4; k++) {
        int newI = i + dir[k][0];
        int newJ = j + dir[k][1];
        if (newI < 0 || newJ < 0 || newI >= n || newJ >= m || board[newI][newJ] != word[s - 1]) continue;
        char ch = board[newI][newJ];
        board[newI][newJ] = '-';
        if (existHelper(board, newI, newJ, n, m, word, s - 1)) {
            return true;   
        }
        board[newI][newJ] = ch;
    }
    
    return false;
    
}
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    int s = word.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[s - 1]) {
                char ch = board[i][j];
                board[i][j] = '-';
                if (existHelper(board, i, j, n, m, word, s - 1)) {
                    return true;   
                }
                board[i][j] = ch;
            }
        }
    }
    return false;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    string word;
    getline(cin, word);
    cout << exist(board, word) << '\n';
    return 0;
}