void stepnumHelper(int A, int B, int i, vector<int> &res) {
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        if (n >= A && n <= B)
            res.push_back(n);
        if(n == 0 || n > B)
            continue;
        int last = n % 10;
        int first = n * 10 + last - 1;
        int second = n * 10 + last + 1;
        if (last == 0) {
            q.push(second);
        }
        else if (last == 9) {
            q.push(first);
        }
        else {
            q.push(first);
            q.push(second);
        }
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> res;
    for (int i = 0; i <= 9; i++) {
        stepnumHelper(A, B, i, res);
    }
    sort(res.begin(), res.end());
    return res;
}
