#include <bits/stdc++.h>
using namespace std;

int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int n = nums.size();
    int prev = 0;
    int last_invalid = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int curr = nums[i];
        if (curr > right){
            last_invalid = i;
            prev = 0;
        }
        else if (curr < left) {
            ans += prev;
        }
        else if (curr >= left && curr <= right) {
            prev = i - last_invalid;
            ans += prev;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 9, 2, 5, 6};
    int left = 2;
    int right = 8;
    cout << numSubarrayBoundedMax(nums, left, right) << '\n';
    return 0;
}