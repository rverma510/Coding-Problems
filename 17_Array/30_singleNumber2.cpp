// https://leetcode.com/problems/single-number-ii

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }
    for (auto &i: mp) {
        if (i.second == 1) {
            return i.first;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << singleNumber(nums) << '\n';
    return 0;
}