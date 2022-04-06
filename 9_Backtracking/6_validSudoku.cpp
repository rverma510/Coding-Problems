

#include <bits/stdc++.h>
using namespace std;

bool checkRow(vector<vector<char>> &board, int i, int j) {
    for (int k = 0; k < 9; k++) {
        if (j == k) continue;
        if (board[i][j] == board[i][k]) {
            return false;
        }
    }
    return true;
}
bool checkCol(vector<vector<char>> &board, int i, int j) {
    for (int k = 0; k < 9; k++) {
        if (i == k) continue;
        if (board[i][j] == board[k][j]) {
            return false;
        }
    }
    return true;
}
bool checkBlock(vector<vector<char>> &board, int i, int j) {
    int rowStart = (i / 3) * 3;
    int colStart = (j / 3) * 3;
    for (int k = rowStart; k < rowStart + 3; k++) {
        for (int l = colStart; l < colStart + 3; l++) {
            if (k == i && l == j) continue;
            if (board[i][j] == board[k][l]) {
                return false;
            }
        }
    }
    return true;
}
bool check(vector<vector<char>> &board, int i, int j) {
    return checkRow(board, i, j) &&
        checkCol(board, i, j) &&
        checkBlock(board, i, j);
}
bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.' && !check(board, i, j)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'}, 
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};

    cout << isValidSudoku(board) << '\n';
    return 0;
}