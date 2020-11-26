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

ll n;
vector<ll> graph[maxn];
vector<ll> s(maxn);
vector<ll> a(maxn);

void func_sum(ll v, ll p, ll depth, ll sum_p) {
    if (depth & 1) {
        a[v] = s[v] - sum_p;
        for (auto u: graph[v]) {
            func_sum(u, v, depth + 1, s[v]);
        }
    }
    else {
        a[v] = graph[v].size() != 0 ? 1e18 : 0;
        for (auto u: graph[v]) {    
            a[v] = min(a[v], s[u] - s[p]);
        }
        s[v] = s[p] + a[v];
        for (auto u: graph[v]) {
            func_sum(u, v, depth + 1, s[v]);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        ll p; cin >> p; p--;
        graph[p].pb(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    func_sum(0, -1, 1, 0);
    ll ans = 0;
    for (auto i: a) {
        if (i < 0) {
            ans = -1;
            break;
        }
        ans += i;
    }
    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}