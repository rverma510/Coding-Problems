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

int n;
vector<int> graph[maxn];
int color[maxn];

bool dfs(int v, int p, int c) {
    if (color[v] != c) return false;
    for (auto u: graph[v]) {
        if (u != p) {
            if (!dfs(u, v, c)) return false;
        }
    }
    return true;
}

bool check(int root) {
    for (auto v: graph[root]) {
        if (!dfs(v, root, color[v])) return false;
    }
    return true;
}

void solve() {
    cin >> n;
    for (int u, v, i = 0; i < n - 1; i++) {
        cin >> u >> v; u--; v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for (int i = 0; i < n; i++) cin >> color[i];
    int root1 = -1, root2 = -1;
    for (int i = 0; i < n; i++) {
        for (auto j: graph[i]) {
            if (color[i] != color[j]) {
                root1 = i;
                root2 = j;
                break;
            }
        }
    }
    if (root1 == -1) {
        cout << "YES\n1";
        return;
    }
    bool res1 = check(root1);
    bool res2 = check(root2);
    if (res1) cout << "YES\n" << root1 + 1;
    else if (res2) cout << "YES\n" << root2 + 1;
    else cout << "NO\n";
}

int main() {
    speed;
    solve();
    return 0;
}