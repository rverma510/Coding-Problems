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

int t, n, k;

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
    cin >> n >> k;
    vector<vector<pii>> arr;
    for (int tmp, i = 0; i < n; i++) {
        cin >> tmp;
        vector<pii> a;
        while (tmp > 1) {
            int p = prime[tmp];
            int cnt = 0;
            while (tmp % p == 0) tmp /= p, cnt++;
            if (cnt % k != 0) {
                a.pb({p, cnt % k});
            }
        }
        arr.pb(a);
    }
    map<vector<pii>, int> m;
    m[arr[0]]++;
    ll ans = 0;
    for (int i = 1; i < (int)arr.size(); i++) {
        vector<pii> tmp = arr[i];
        for (int j = 0; j < (int) tmp.size(); j++) {
            tmp[j].se = k - tmp[j].se;
        }
        if (m.find(tmp) != m.end()) ans += m[tmp];
        m[arr[i]]++;
    }
    cout << ans << endl;
}

int main() {
    speed;
    sieve();
    solve();
    return 0;
}