// https://leetcode.com/problems/gray-code

#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> res(1, 0);
    for (int i = 0; i < n; i++) {
        int sz = res.size();
        for (int j = sz - 1; j >= 0; j--) {
            res.push_back(res[j] | 1<<i);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> res = grayCode(n);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}