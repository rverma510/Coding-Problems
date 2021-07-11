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
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;

const double pi = acos(-1.0);
const int maxn = 1e6 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ld scale = 1e6;

int t, n;
int a[maxn], b[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (b[i] - a[i] > 0) {
            for (int j = 0; j < b[i] - a[i]; j++) {
                pos.pb(i + 1);
            }
        }
        else if (b[i] - a[i] < 0) {
            for (int j = 0; j < a[i] - b[i]; j++) {
                neg.pb(i + 1);
            }
        }
    }
    if (pos.size() == neg.size()) {
        cout << pos.size() << '\n';
        for (int i = 0; i < pos.size(); i++) {
            cout << neg[i] << ' ' << pos[i] << '\n';
        } 
    }
    else {
        cout << -1 << '\n';
    }
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}