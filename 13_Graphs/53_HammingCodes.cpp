#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int n, b, d;
set<int> ans;

int main() {
    speed;
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    cin >> n >> b >> d;
    ans.insert(0);
    for (int i = 1; i < 1<<b && ans.size() < n; i++) {
        int mx = 8;
        for (auto j: ans) {
            int cnt = 0;
            int tmp = i ^ j;
            for (int k = 0; k < 8; k++) {
                if (tmp & (1 << k)) cnt++;
            }
            mx = min(mx, cnt); 
        }
        if (mx >= d) ans.insert(i);
    }
    int i = 0;

    for (auto j: ans) {
        if (i == n - 1 || (i + 1) % 10 == 0) cout << j << '\n';
        else cout << j << ' ';    
        i++;
    }
    return 0;
}