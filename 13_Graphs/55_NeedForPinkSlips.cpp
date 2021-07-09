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

int t;

ld helper(ll c, ll m, ll p, ll v, int level) {
    ld ans = (p / scale) * level;
    if (c > 0) {
        if (c > v) {
            if (m > 0) {
                ans += (c / scale) * helper(c - v, m + v / 2, p + v / 2, v, level + 1);
            }
            else {
                ans += (c / scale) * helper(c - v, 0, p + v, v, level + 1);
            }
        }
        else {
            if (m > 0) {
                ans += (c / scale) * helper(0, m + c / 2, p + c / 2, v, level + 1);
            }
            else {
                ans += (c / scale) * helper(0, 0, p + c, v, level + 1);
            }
        }
    }
    if (m > 0) {
        if (m > v) {
            if (c > 0) {
                ans += (m / scale) * helper(c + v / 2, m - v, p + v / 2, v, level + 1);
            }
            else {
                ans += (m / scale) * helper(0, m - v, p + v, v, level + 1);
            }
        }
        else {
            if (c > 0) {
                ans += (m / scale) * helper(c + m / 2, 0, p + m / 2, v, level + 1);
            }
            else {
                ans += (m / scale) * helper(0, 0, p + m, v, level + 1);
            }
        }
    }
    return ans;
}

void solve() {
    ld cd, md, pd, vd;
    cin >> cd >> md >> pd >> vd;
    ll c = round(cd * scale);
    ll m = round(md * scale);
    ll p = round(pd * scale);
    ll v = round(vd * scale);
    cout << setprecision(12) << fixed << helper(c, m, p, v, 1) << '\n';
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}