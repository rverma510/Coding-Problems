#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int x[13], y[13];
int partner[13];
int next_on_right[13];

bool cycle_exists() {
    for (int start = 1; start <= n ; start++) {
        int pos = start;
        for (int cnt = 1; cnt <= n; cnt++) {
            pos = next_on_right[partner[pos]];
        }
        if (pos != 0) return true;   
    }
    return false;
}

int solve() {
    int i, total = 0;
    for (i = 1; i <= n; i++) {
        if (partner[i] == 0) break;
    }
    if (i > n) {
        if (cycle_exists()) return 1;
        else return 0;
    } 
    for (int j = i + 1; j <= n; j++) {
        if (partner[j] == 0) {
            partner[i] = j;
            partner[j] = i;
            total += solve();
            partner[i] = partner[j] = 0;
        }
    }
    return total;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[j] > x[i] && y[i] == y[j]) {
                if (next_on_right[i] == 0 || x[j] - x[i] < x[next_on_right[i]] - x[i]) {
                    next_on_right[i] = j;
                }
            }
        }
    }
    cout << solve() << '\n';
    return 0;
}