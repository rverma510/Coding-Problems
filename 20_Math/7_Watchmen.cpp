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

int n;
map<pii, int> m;
map<int, int> x;
map<int, int> y;

void solve() {
    cin >> n;
    for (int a, b, i = 0; i < n; i++) {
        cin >> a >> b;
        m[{a, b}]++;
        x[a]++;
        y[b]++;
    }
    ll ans = 0;
    for (auto i: m) {
        int a = i.fi.fi;
        int b = i.fi.se;
        int cnt = i.se;
        while (cnt > 0 ) {
            ans += x[a] + y[b] - cnt - 1;
            x[a]--;
            y[b]--;
            cnt--;
        }
    }
    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}