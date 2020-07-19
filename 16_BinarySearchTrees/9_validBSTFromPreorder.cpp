int Solution::solve(vector<int> &A) {
    stack<int> s;
    int root = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < root)
            return false;
        while (!s.empty() && s.top() < A[i]) {
            root = s.top();
            s.pop();
        }
        s.push(A[i]);
    }
    return true;
}
