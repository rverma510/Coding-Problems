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
const int maxn = 2e3 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n;
vector<int> graph[maxn];

void solve() {
    cin >> n;
    vector<int> roots;
    for (int tmp, i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == -1) {
            roots.pb(i);
        }
        else {
            graph[tmp - 1].pb(i);
        }
    }
    int ans = 0;
    for (auto r: roots) {
        int l = 0;
        queue<int> q;
        q.push(r);
        while (!q.empty()) {
            l++;
            int sz = q.size();
            while (sz--) {
                int v = q.front(); q.pop();
                for (auto u: graph[v]) {
                    q.push(u);
                }
            }
        }
        ans = max(ans, l);
    }
    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}