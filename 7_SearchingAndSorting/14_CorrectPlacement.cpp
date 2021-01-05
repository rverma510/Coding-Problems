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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, pair<ll, ll>> plll;
const int mod = 1e9 + 7;

const double pi = acos(-1.0);
const int maxn = 2e5 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int t, n;
plll p[maxn];
ll res[maxn];
ll bia[maxn];
ll bva[maxn];

bool compare(const plll &a, const plll &b) {
    return a.se.fi < b.se.fi;
}

void solve() {
    cin >> n;
    for (int x, y, i = 0; i < n; i++) {
        cin >> x >> y;
        if (x < y) {
            p[i].se.fi = x;
            p[i].se.se = y;
        }
        else {
            p[i].se.fi = y;
            p[i].se.se = x;
        }
        p[i].fi = i;
    }
    sort(p, p + n, compare);
    ll bi = -1, bv = 1e9 + 7, pt = -1;
    for (int i = 0; i < n; i++) {
        res[p[i].fi] = -1;
        if (i > 0) {
            if (p[i].se.fi != p[i - 1].se.fi) pt = i - 1;
            if (pt >= 0 && p[i].se.se > bva[pt]) {
                res[p[i].fi] = bia[pt];
            }
        }
        if (p[i].se.se < bv) {
            bv = p[i].se.se;
            bi = p[i].fi + 1;
        }
        bva[i] = bv;
        bia[i] = bi;
    }
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    cout << endl;
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}