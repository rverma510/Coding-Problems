#include <bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int n = nums1.size();
    map<int, int> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[-nums1[i] - nums2[j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt += m[nums3[i] + nums4[j]];
        }
    }
    return cnt;
}

int main() {
    vector<int> nums1 = {0, 1, -1};
    vector<int> nums2 = {-1, 1, 0};
    vector<int> nums3 = {0, 0, 1};
    vector<int> nums4 = {-1, 1, 1};
    int target = 2;
    int res = fourSumCount(nums1, nums2, nums3, nums4);
    cout << res << '\n';
    return 0;
}