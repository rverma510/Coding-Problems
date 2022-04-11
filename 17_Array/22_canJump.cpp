// https://leetcode.com/problems/jump-game/

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int currEnd = 0;
    int currFarthest = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        currFarthest = max(currFarthest, i + nums[i]);
        if (i == currEnd) {
            currEnd = currFarthest;
        }
    }
    if (currEnd >= n - 1) {
        return true;
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
    cout << canJump(nums) << '\n';
    return 0;
}