#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = -1, diff = INT_MAX;
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int tmp = nums[i] + nums[l] + nums[r];
            if (tmp == target) {
                return target;
            }
            else if (tmp > target) {
                if (diff > abs(target - tmp)) {
                    diff = abs(target - tmp);
                    ans = tmp;
                }
                r--;
            }
            else {
                if (diff > abs(target - tmp)) {
                    diff = abs(target - tmp);
                    ans = tmp;
                }
                l++;
            }
        }
        
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 0, -1, 2, -1, 4};
    int target = 2;
    cout << threeSumClosest(nums, target) << '\n';
    return 0;
}