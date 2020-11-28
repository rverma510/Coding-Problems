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
const ll inf = 1e18;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

ll n, m;
vector<pll> graph[maxn];
vector<ll> parent(maxn, -1);
vector<ll> dist(maxn, inf);

void solve() {
    cin >> n >> m;
    for (ll x, y, w, i = 0; i < m; i++) {
        cin >> x >> y >> w; x--; y--;
        graph[x].pb(mp(y, w));
        graph[y].pb(mp(x, w));
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
        ll v = pq.top().se;
        pq.pop();
        for (auto u: graph[v]) {
            if (dist[u.fi] > dist[v] + u.se) {
                dist[u.fi] = dist[v] + u.se;
                parent[u.fi] = v;
                pq.push({dist[u.fi], u.fi});
            }
        }
    }
    if (parent[n - 1] == -1) {
        cout << -1;
        return;
    }
    ll v = n - 1;
    vector<ll> res;
    while (v != -1) {
        res.pb(v + 1);
        v = parent[v];
    }
    for (ll i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';
}

int main() {
    speed;
    solve();
    return 0;
}