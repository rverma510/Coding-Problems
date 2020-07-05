// https://leetcode.com/problems/median-of-two-sorted-arrays/
/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int lo = 0;
        int hi = nums1.size();
        int total = nums1.size() + nums2.size();
        while (lo <= hi) {
            int partX = (lo + hi) / 2;
            int partY = (total + 1) / 2 - partX;
            
            int leftX = getMax(nums1, partX);
            int leftY = getMax(nums2, partY);
            int rightX = getMin(nums1, partX);
            int rightY = getMin(nums2, partY);
            
            if (leftX <= rightY && leftY <= rightX) {
                if (total % 2 == 0) {
                    return (max(leftX, leftY) + min(rightX, rightY)) / 2.0;
                }
                else {
                    return max(leftX, leftY);
                }
            }
            else if (leftX > rightY) {
                hi = partX - 1;
            }
            else {
                lo = partX + 1;
            }
        }
        return -1;
    }
    
    int getMax(vector<int>& nums, int partition) {
        if (partition == 0) {
            return INT_MIN;
        }
        else {
            return nums[partition - 1];
        }
    }
    
    int getMin(vector<int>& nums, int partition) {
        if (partition == nums.size()) {
            return INT_MAX;
        }
        else {
            return nums[partition];
        }
    }
    
};