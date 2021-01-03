#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    int n, s, c;
    cin >> n >> s >> c;
    vector<int> stall;
    for (int tmp, i = 0; i < c; i++) {
        cin >> tmp;
        stall.push_back(tmp);
    }
    sort(stall.begin(), stall.end());
    vector<int> gap;
    for (int tmp, i = 1; i < c; i++) {
        tmp = stall[i] - stall[i - 1] - 1;
        if (tmp > 0) gap.push_back(tmp);
    }
    sort(gap.begin(), gap.end());
    ll ans = 0;
    for (int i = 0; i < (int) gap.size() - n + 1; i++) {
        ans += gap[i];
    }
    cout << ans + c << endl;
    return 0;
}