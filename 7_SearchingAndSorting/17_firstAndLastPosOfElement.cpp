// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

#include <bits/stdc++.h>
using namespace std;

int findStartPos(vector<int> &nums, int target) {
    int l = 0, h = nums.size() - 1;
    int ans = -1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (nums[m] == target) {
            ans = m;
            h = m - 1;
        }
        else if (nums[m] > target) {
            h = m - 1;
        }
        else {
            l = m + 1;
        }
    } 
    return ans;
}

int findEndPos(vector<int> &nums, int target) {
    int l = 0, h = nums.size() - 1;
    int ans = -1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (nums[m] == target) {
            ans = m;
            l = m + 1;
        }
        else if (nums[m] > target) {
            h = m - 1;
        }
        else {
            l = m + 1;
        }
    } 
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target) {
    int a = findStartPos(nums, target);
    int b = findEndPos(nums, target);
    return {a, b};
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    vector<int> res = searchRange(nums, target);
    cout << res[0] << ' ' << res[1] << '\n';
    return 0;
}