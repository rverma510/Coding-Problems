// https://leetcode.com/problems/maximum-product-subarray
// https://leetcode.com/problems/maximum-product-subarray/discuss/203013/C%2B%2B-O(N)-time-O(1)-space-solution-with-explanation

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int res = nums[0];
    int mx = nums[0];
    int mn = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[i] < 0) {
            swap(mx, mn);
        }
        mx = max(nums[i], nums[i] * mx);
        mn = min(nums[i], nums[i] * mn);
        
        res = max(res, mx);
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << maxProduct(nums) << '\n';
    return 0;
}