#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int l = j + 1, r = n - 1;
            while (l < r) {
                int tmp = nums[i] + nums[j] + nums[l] + nums[r];
                if (tmp == target) {
                    res.push_back({
                        nums[i],
                        nums[j],
                        nums[l],
                        nums[r]
                    });
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++; r--;
                }
                else if(tmp > target) r--;
                else l++;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 0, -1, 2, -1, 4};
    int target = 2;
    vector<vector<int>> res = fourSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << ' ' << res[i][3] << '\n';
    }
    return 0;
}