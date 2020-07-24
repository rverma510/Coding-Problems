#include <bits/stdc++.h>
using namespace std;
int calculateLIS(vector<int> &&v) {
    int n = v.size();
    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    int mx = INT_MIN;
    for (auto i: lis){
        mx = max(mx, i);
    }
    return mx;
}
int main() {
    int n, tmp;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << calculateLIS(move(v)) << "\n";
    return 0;
}

/*

9
10 22 9 33 21 50 41 60 80

*/