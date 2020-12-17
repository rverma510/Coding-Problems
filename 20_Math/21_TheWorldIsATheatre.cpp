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
const int mod = 1e9 + 7;

const double pi = acos(-1.0);
const int maxn = 3e1 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a * 1ll) % mod;
        }
        a = (a * a * 1ll) % mod;
        b /= 2;
    }
    return res;
}

ll f[maxn];
ll finv[maxn];
void fact() {
    f[0] = 0;
    f[1] = 1;
    int i;
    for (i = 2; i < maxn; i++) {
        f[i] = (f[i - 1] * i * 1ll) % mod;
    }
    i--;
    finv[i] = power(f[i], mod - 2);
    for (i--; i >= 0; i--) {
        finv[i] = (finv[i + 1] * (i + 1) * 1ll) % mod;
    }
}

ll mul(int x, int y) {
    return (x * 1ll * y) % mod;
}

ll ncr(int a, int b) {
    if (b < 0 || a < 0 || b > a) return 0;
    return mul(f[a], mul(finv[a - b], finv[b]));
}

ll n, m, t;

void solve() {
    cin >> n >> m >> t;
    if (t > n + m) {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    int i = t - 1, j = 1;
    int tmp = i - n;
    if (tmp >= 0) {
        i -= tmp;
        j += tmp;
    }
    while (i >= 4 && i <= n && j >= 1 && j <= m) {
        ans += (1ll * ncr(n, i) * ncr(m, j));
        i--;
        j++;
    }
    cout << ans << endl;
}

int main() {
    speed;
    fact();
    solve();
    return 0;
}