#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, tmp;
        cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            m[tmp]++;
        }
        int freq = INT_MAX;
        int ans = -1;
        for (auto i: m) {
            if (freq > i.second) {
                ans = i.first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}