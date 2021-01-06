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
const int maxn = 1e6 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int t, n, q;

int prime[maxn];
void sieve() {
    bool p[maxn];
    mem(p, true);
    p[0] = p[1] = 0;
    for (ll i = 2; i < maxn; i++) {
        if (p[i]) {
            prime[i] = i;
            for (ll j = i * i * 1ll; j < maxn; j += i) {
                if (p[j]) {
                    prime[j] = i;
                    p[j] = false;
                }
            }
        }
    }
}

void solve() {
    cin >> n;
    map<int, int> m;
    for (int tmp, i = 0; i < n; i++) {
        cin >> tmp;
        int ans = 1;
        while (tmp > 1) {
            int p = prime[tmp];
            int cnt = 0;
            while (tmp % p == 0) tmp /= p, cnt++;
            if (cnt & 1) ans *= p;
        }
        m[ans]++;
    }
    int a = 0, b = 0;
    for (auto i: m) {
        a = max(a, i.se);
        if (i.fi == 1 || !(i.se & 1)) b += i.se;
    }
    b = max(b, a);
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll w; cin >> w;
        if (w == 0) cout << a << endl;
        else cout << b << endl;
    }
}

int main() {
    speed;
    sieve();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}