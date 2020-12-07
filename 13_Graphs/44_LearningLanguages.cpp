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
const int maxn = 1e2 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, m;
vector<int> emp[maxn];
vector<int> lang[maxn];
vector<bool> visited(maxn, false);

void dfs(int v) {
    visited[v] = true;
    for (auto l: emp[v]) {
        for (auto u: lang[l]) {
            if (!visited[u]) dfs(u);
        }
    }
}

void solve() {
    cin >> n >> m;
    bool pres = false;
    for (int k, i = 0; i < n; i++) {
        cin >> k;
        if (k > 0) pres = true;
        for (int tmp, j = 0; j < k; j++) {
            cin >> tmp; tmp--;
            emp[i].pb(tmp);
            lang[tmp].pb(i);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    if (pres) cout << cnt - 1 << endl;
    else cout << cnt << endl;
}

int main() {
    speed;
    solve();
    return 0;
}