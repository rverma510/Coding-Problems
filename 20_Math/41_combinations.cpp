// 

#include <bits/stdc++.h>
using namespace std;

void helper(int n, int k, vector<int> &ans, vector<vector<int>> &res) {
    if (k == 0) {
        res.push_back(ans);
        return;
    }
    int m = ans.size();
    int l = ans[m - 1];
    for (int i = l + 1; i <= n; i++) {
        ans.push_back(i);
        helper(n, k - 1, ans, res);
        ans.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    for (int i = 1; i < n - k + 2; i++) {
        vector<int> ans = {i};
        helper(n, k - 1, ans, res);
    }
    return res;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> res = combine(n, k);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}