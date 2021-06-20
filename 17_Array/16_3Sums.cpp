#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < n - 2; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (nums[i] + nums[l] + nums[r] == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (r > l && nums[r] == nums[r - 1]) r--;
                l++; r--;
            }
            else if (nums[i] + nums[l] + nums[r] > 0) {
                r--;
            }
            else {
                l++;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 0, -1, 2, -1, 4};
    vector<vector<int>> res = threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << '\n';
    }
    return 0;
}