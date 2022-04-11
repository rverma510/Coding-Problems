// https://leetcode.com/problems/insert-interval/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int n = intervals.size();
    int i = 0;
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++; 
    }
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n);
    for (int i = 0; i < n; i++) {
        vector<int> interval(2);
        cin >> interval[0] >> interval[1];
        intervals[i] = interval;
    }
    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];
    vector<vector<int>> res = insert(intervals, newInterval);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << ' ' << res[i][1] << '\n';
    }
    return 0;
}