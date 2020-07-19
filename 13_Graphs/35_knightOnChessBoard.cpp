int delta[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

bool isSafe(int x, int y, int M, int N) {
    if (x < 1 || x > M || y < 1 || y > N)
        return false;
    return true;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>> moves(A + 1, vector<int>(B + 1, -1));
    vector<vector<bool>> visited(A + 1, vector<bool>(B + 1, false));
    queue<pair<int, int>> q;
    q.push({C, D});
    pair<int, int> p;
    moves[C][D] = 0;
    visited[C][D] = true;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x = p.first + delta[i][0];
            int y = p.second + delta[i][1];
            if (!isSafe(x, y, A, B))
                continue;
            moves[x][y] = (moves[x][y] == -1) ? moves[p.first][p.second] + 1 : 
                            min (moves[x][y], moves[p.first][p.second] + 1);
            if (visited[x][y])
                continue;
            q.push({x, y});
            visited[x][y] = true;
        }   
    }
    if (visited[E][F]) {
        return moves[E][F];
    }
    return -1;
}