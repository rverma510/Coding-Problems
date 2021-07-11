#include <bits/stdc++.h>
using namespace std;

#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rf freopen("in.txt", "r", stdin);
#define wf freopen("out.txt", "w", stdout);

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define mem(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;

const double pi = acos(-1.0);
const int maxn = 1e6 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ld scale = 1e6;

struct AC{
    int idx, t;
};

bool compare(const AC &a, const AC &b) {
    return a.t < b.t;
}

int t, n, k;

void solve() {
    cin >> n >> k;
    AC ac[k]; 
    ll ans[n + 1];
    for (int i = 0; i <= n; i++) ans[i] = 1e18;
    for (int i = 0; i < k; i++) {
        cin >> ac[i].idx;
    }
    for (int i = 0; i < k; i++) {
        cin >> ac[i].t;
        ans[ac[i].idx] = ac[i].t;
    }
    sort(ac, ac + k, compare);
    for (int i = 0; i < k; i++) {
        AC tmp = ac[i];
        if (ans[tmp.idx] < tmp.t) continue;
        int l = tmp.idx - 1, r = tmp.idx + 1;
        while (l > 0 && ans[l] > ans[l + 1] + 1) {
            ans[l] = ans[l + 1] + 1;
            l--;
        }
        while (r <= n && ans[r] > ans[r - 1] + 1) {
            ans[r] = ans[r - 1] + 1;
            r++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}