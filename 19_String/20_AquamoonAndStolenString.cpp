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
const int maxn = 1e5 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ld scale = 1e6;

int t, n, m;
ll a[maxn];

void solve() {
    cin >> n >> m; char ch; cin.get(ch);
    mem(a, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[j] += (s[j] - 'a' + 1);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[j] -= (s[j] - 'a' + 1);
        }
    }
    for (int i = 0; i < m; i++) {
        cout << (char)(a[i] + 'a' - 1);
    }
    cout << '\n';
    cout.flush();
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}