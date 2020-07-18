const int delta[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void solveHelper(int x, int y, vector<vector<char>> &A) {
    A[x][y] = '-';
    for (int i = 0; i < 4; i++) {
        int new_x = x + delta[i][0];
        int new_y = y + delta[i][1];
        if (new_x < 0 || new_x >= A.size() || new_y < 0 || new_y >= A[0].size() 
            || A[new_x][new_y] != 'O')
            continue;
        solveHelper(new_x, new_y, A);
    }
}
void Solution::solve(vector<vector<char> > &A) {
    int m = A.size(), n = A[0].size();
    for (int i = 0; i < n; i++) {
        if (A[0][i] == 'O') solveHelper(0, i, A);
        if (A[m - 1][i] == 'O') solveHelper(m - 1, i, A);
    }
    for (int i = 0; i < m; i++) {
        if (A[i][0] == 'O') solveHelper(i, 0, A);
        if (A[i][n - 1] == 'O') solveHelper(i, n - 1, A);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == '-') A[i][j] = 'O';
            else A[i][j] = 'X';
        }
    }
}
