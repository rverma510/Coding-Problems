#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 30;
int v, g;
int req[maxn];
int feed[maxn][maxn];
int ans{maxn};
int order{-1};

void solve(int idx, int cnt, int num) {
    int j;
    for (j = 0; j < v; j++) {
        if (req[j] > 0) break;
    }
    if (j >= v) {
        ans = cnt;
        order = num;
        return;
    }
    while (idx < g && cnt + 1 < ans) {
        for (j = 0; j < v; j++) {
            req[j] -= feed[idx][j];
        }
        num += (1<<idx);
        solve(idx + 1, cnt + 1, num);
        for (j = 0; j < v; j++) {
            req[j] += feed[idx][j];
        }
        num -= (1<<idx);
        idx++;
    }
}

int main() {
    speed;
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    cin >> v;
    for (int i = 0; i < v; i++) {
        cin >> req[i];
    }
    cin >> g;
    for (int i = 0; i < g; i++) {
        for (int j = 0; j < v; j++) {
            cin >> feed[i][j];
        }
    }
    ans = g + 1;
    solve(0, 0, 0);
    cout << ans;
    for (int i = 0; i < 31; i++) {
        if (order & (1 << i)) cout << ' ' << (i + 1);
    }
    cout << '\n';
    return 0;
}