// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
            return true;
        }
        if (nums[m] == nums[l]) {
            l++;
            continue;
        }
        bool pivot = nums[l] <= nums[m];
        bool tar = nums[l] <= target;
        if (pivot ^ tar) {
            if (tar) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        else {
            if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
    }
    
    return false;
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
    cout << search(nums, target) << '\n';
    return 0;
}
/*
5
1 0 1 1 1
0
*/