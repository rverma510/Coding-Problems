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
int arr[maxn];
vector<int> graph[maxn];
bool vis[maxn];

void dfs(int v, int &mx) {
    vis[v] = true;
    mx = min(mx, arr[v]);
    for (auto u: graph[v]) {
        if (!vis[u]) dfs(u, mx);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int x, y, i = 0; i < m; i++) {
        cin >> x >> y; x--; y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    mem(vis, false);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int mx = INT_MAX;
            dfs(i, mx);
            ans += mx;
        }
    }
    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}