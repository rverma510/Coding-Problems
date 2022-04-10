// https://leetcode.com/problems/permutations-ii

#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &ans, map<int, int> &counts, int n, vector<vector<int>> &res) {
    if (n == 0) {
        res.push_back(ans);
        return;
    }
    for (auto i: counts) {
        int k = i.first;
        int v = i.second;
        if (v == 0) continue;
        counts[k] = v - 1;
        ans[n - 1] = k;
        // cout << n - 1 << ' ' << k << '\n';
        helper(ans, counts, n - 1, res);
        counts[k] = v;
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    map<int, int> counts;
    for (int &i: nums) {
        counts[i]++;
    }
    int n = nums.size();
    vector<int> ans(n);
    vector<vector<int>> res;
    helper(ans, counts, n, res);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> res = permuteUnique(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}