#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, int> pli;

int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    ll dp[n];
    dp[0] = nums[0];
    priority_queue<pli> pq;
    pq.push({dp[0], 0});
    for (int i = 1; i < n; i++) {
        pli p = pq.top();
        while (p.second < i - k) {
            pq.pop();
            p = pq.top();
        }
        dp[i] = nums[i] + p.first;
        pq.push({dp[i], i});
    }
    return dp[n - 1];
}

int main() {
    vector<int> nums = {1, -1, -2, 4, -7, 3};
    int k = 2;
    cout << maxResult(nums, k) << '\n';
    return 0;
}