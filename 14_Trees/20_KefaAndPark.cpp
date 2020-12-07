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

int n, m;
bool is_present[maxn];
vector<int> graph[maxn];

ll dfs(int v, int p, int cnt) {
    // cout << v << ' ' << p << ' ' << cnt << endl; 
    if (cnt > m) return 0;
    ll ans = 0, c = 0;
    for (auto u: graph[v]) {
        if (u != p) {
            c++;
            if (is_present[u]) ans += dfs(u, v, cnt + is_present[u]);
            else ans += dfs(u, v, 0);
        }
    }
    if (c == 0) return 1;
    else return ans;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> is_present[i];
    for (int x, y, i = 0; i < n - 1; i++) {
        cin >> x >> y; x--; y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    cout << dfs(0, -1, is_present[0]) << endl;
}

int main() {
    speed;
    solve();
    return 0;
}