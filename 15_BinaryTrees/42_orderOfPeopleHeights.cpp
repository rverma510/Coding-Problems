vector<int> Solution::order(vector<int> &A, vector<int> &B) {\
    map<int, int, greater<int>> m;
    vector<int> ans;
    for (int i = 0; i < A.size(); i++) {
        m[A[i]] = B[i];
    }
    for (auto i: m) {
        if (ans.empty()) {
            ans.push_back(i.first);
        }
        else {
            ans.insert(ans.begin() + i.second, i.first);
        }
    }
    return ans;
}
