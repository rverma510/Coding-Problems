

#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &nums, int n, vector<int> &ans, vector<vector<int>> &res) {
    if (n == 0) {
        res.push_back(ans);
        return;
    }
    ans.push_back(nums[n - 1]);
    helper(nums, n - 1, ans, res);
    ans.pop_back();
    helper(nums, n - 1, ans, res);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> ans;
    int n = nums.size();
    helper(nums, n, ans, res);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> res = subsets(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}