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
const int maxn = 1e5 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

ll ncr(ll n, ll r = 3) {
    if (r < 0 || n < 0 || r > n)
        return 0;
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res = (res * (n - i + 1) * 1ll) / i;
    }
    return res;
}

ll n, d;
ll arr[maxn];

void solve() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int prev_e = -1;
    int st = 0, e = 2;
    ll ans = 0;
    while (e < n) {
        if (arr[e] - arr[st] <= d) e++;
        else {
            ans += ncr(e - st);
            if (prev_e != -1) ans -= ncr(prev_e - st); 
            prev_e = e;
            st++;
        }
    }
    ans += ncr(e - st);
    if (prev_e != -1) ans -= ncr(prev_e - st);
    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}