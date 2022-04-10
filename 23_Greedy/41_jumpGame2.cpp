// https://leetcode.com/problems/jump-game-ii/

#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int j = 0, currEnd = 0, currFarthest = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        currFarthest = max(currFarthest, i + nums[i]);
        if (i == currEnd) {
            currEnd = currFarthest;
            j++;
        }
    }
    return j;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << jump(nums) << '\n';
    return 0;
}