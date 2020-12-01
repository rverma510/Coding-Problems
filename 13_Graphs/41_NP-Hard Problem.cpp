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

ll t, n, m;
vector<int> graph[maxn];
int visited[maxn];

void solve() {
    cin >> n >> m;
    int mx = -1;
    for (int x, y, i = 0; i < m; i++) {
        cin >> x >> y; 
        graph[x].pb(y);
        graph[y].pb(x);
    }
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] || graph[i].size() == 0) continue;
        queue<int> q;
        q.push(i);
        visited[i] = 2;
        b++;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u: graph[v]) {
                if (!visited[u]) {
                    q.push(u);
                    visited[u] = 3 - visited[v];
                    if (visited[u] == 1) a++;
                    else b++;
                }
                else if (visited[u] == visited[v]) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    cout << a << endl;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 1) cout << i << ' ';
    }
    cout << endl << b << endl;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 2) cout << i << ' ';
    }
}

int main() {
    speed;
    solve();
    return 0;
}