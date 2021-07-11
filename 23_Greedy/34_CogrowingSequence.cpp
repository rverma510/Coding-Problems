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
int x[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<int> y(n, 0);
    for (int i = 1; i < n; i++) {
        int tmp = x[i - 1] ^ y[i - 1];
        for (int j = 0; j < 31; j++) {
            int p = (1 << j);
            if ((tmp & p) && (x[i] & p)) {
                tmp ^= p;
            }
        }
        y[i] = tmp;
    }
    for (int i = 0; i < n; i++) {
        cout << y[i] << ' ';
    }
    cout << '\n';
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}