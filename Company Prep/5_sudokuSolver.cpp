#include <bits/stdc++.h>
using namespace std;

bool find(vector<vector<int>> &mat, int &row, int &col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (mat[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isSafe(vector<vector<int>> &mat, int row, int col, int k) {
    for (int i = 0; i < 9; i++) {
        if (mat[row][i] == k)
            return false;
    }
    for (int i = 0; i < 9; i++) {
        if (mat[i][col] == k)
            return false;
    }
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[boxRowStart + i][boxColStart + j] == k)
                return false;
        }
    }
    return true;
}

bool sudoku(vector<vector<int>> &mat) {
    int row, col;
    if (!find(mat, row, col))
        return true;
    for (int k = 1; k <= 9; k++) {
        if (isSafe(mat, row, col, k)) {
            mat[row][col] = k;
            if (sudoku(mat))
                return true;
            mat[row][col] = 0;
        }
    }
    return false;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
	    vector<vector<int>> mat(9, vector<int>(9, 0));
	    for (int i = 0; i < 9; i++) {
	        for (int j = 0; j < 9; j++) {
	            cin >> mat[i][j];
	        }
	    }
	    cout << sudoku(mat) << endl;
	}
	return 0;
}