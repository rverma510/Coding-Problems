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

ll t, n;
vector<int> g[maxn];

ld path_average(ll v, ll p) {
    ld sum = 0;
    for (auto u: g[v]) {
        if (u != p) {
            sum += path_average(u, v) + 1;
        }
    }
    return sum ? sum / (g[v].size() - (p != -1)) : 0;    
}

void solve() {
    cin >> n;
    for (int u, v, i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    cout << fixed << setprecision(7) << path_average(0, -1) << endl;
}

int main() {
    speed;
    solve();
    return 0;
}