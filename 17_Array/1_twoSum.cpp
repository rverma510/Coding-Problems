// https://leetcode.com/problems/two-sum/
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
    return {-1, -1};
    }
};
int main() {
    int n, target;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n ; i++) 
        cin>>nums[i];
    cin>>target;
    Solution sol;
    vector<int> res = sol.twoSum(nums, target);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}