int cycleUtil(vector<vector<int>> &adj, int i, vector<bool> &visited, vector<bool> &stack) {
    if (visited[i] == false) {
        visited[i] = true;
        stack[i] = true;
        for (auto j: adj[i]) {
            if (!visited[j] && cycleUtil(adj, j, visited, stack))
                return true;
            else if (stack[j])
                return true;
        }
    }
    stack[i] = false;
    return false;
}
int cycle(vector<vector<int>> &adj, int A) {
    vector<bool> visited(A + 1, false);
    vector<bool> stack(A + 1, false);
    for (int i = 1; i <= A; i++) {
        if (cycleUtil(adj, i, visited, stack))
            return true;
    } 
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<vector<int>> adj(A + 1);
    for (int i = 0; i < B.size(); i++) {
        adj[B[i]].push_back(C[i]);
    }
    return !cycle(adj, A);
}
