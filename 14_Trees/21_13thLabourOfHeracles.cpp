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

int t, n;

void solve() {
    cin >> n;
    int w[n], deg[n];
    mem(w, 0);
    mem(deg, 0);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int x, y, i = 0; i < n - 1; i++) {
        cin >> x >> y;
        deg[x - 1]++;
        deg[y - 1]++;
    }
    ll ans = 0;
    vector<int> seq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < deg[i] - 1; j++) {
            seq.pb(w[i]);
        }
        ans += w[i];
    }
    sort(seq.rbegin(), seq.rend());
    cout << ans;
    for (auto i: seq) {
        ans += i;
        cout << ' ' << ans;
    }
    cout << endl;
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}