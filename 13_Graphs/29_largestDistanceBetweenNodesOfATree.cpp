int solveHelper(vector<vector<int>> &adj, int root, int &ans) {
    if (adj[root].size() == 0) 
        return 1;
    int max1 = 0, max2 = 0;
    for(auto i: adj[root]) {
        int h = solveHelper(adj, i, ans);
        if (h > max1) {
            max2 = max1;
            max1 = h;
        }
        else if (h > max2) {
            max2 = h;
        }
    }
    ans = max(ans, max1 + max2);
    return 1 + max(max1, max2);
}
int Solution::solve(vector<int> &A) {
    int root = -1;
    vector<vector<int>> adj(A.size());
    for(int i = 0; i < A.size(); i++) {
        if (A[i] == -1){
            root = i;
        }
        else {
            adj[A[i]].push_back(i);
        }
    }
    if (adj[root].size() == 0)
        return 0;
    int ans = 0;
    solveHelper(adj, root, ans);
    return ans;
}
