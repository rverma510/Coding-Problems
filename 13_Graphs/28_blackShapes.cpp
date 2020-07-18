int delta[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void blackHelper(vector<string> &A, int x, int y, int m, int n) {
    A[x][y] = '0';
    for (int i = 0; i < 4; i++) {
        int new_x = x + delta[i][0];
        int new_y = y + delta[i][1];
        if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || A[new_x][new_y] != 'X')
            continue;
        blackHelper(A, new_x, new_y, m, n);
    }
}

int Solution::black(vector<string> &A) {
    int count = 0;
    int m = A.size(), n = A[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(A[i][j] == 'X') {
                count++;
                blackHelper(A, i, j, m, n);
            }
        }
    }
    return count;
}