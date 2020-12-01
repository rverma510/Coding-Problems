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
const int maxn = 5e2 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, m, k;
// char graph[maxn][maxn];
vector<string> graph(maxn);
bool visited[maxn][maxn];

pii find_empty_cell() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == '.') return {i, j};
        }
    }
    return {-1, -1};
}

void dfs(int i, int j) {
    visited[i][j] = true;
    if (k == 0) return;
    for (int l = 0; l < 4; l++) {
        int x = i + dir[l][0];
        int y = j + dir[l][1];
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) continue;
        if (graph[x][y] == '.') dfs(x, y);
    }
    if (k > 0) {
        graph[i][j] = 'X';
        k--;
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }
    pii idx = find_empty_cell();
    if (idx.fi != -1) dfs(idx.fi, idx.se);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
}

int main() {
    speed;
    solve();
    return 0;
}