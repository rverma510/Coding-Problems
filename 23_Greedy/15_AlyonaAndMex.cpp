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

int n, m;

void solve() {
    cin >> n >> m;
    int mn = INT_MAX;
    for (int l, r, i = 0; i < m; i++) {
        cin >> l >> r;
        mn = min(mn, r - l + 1);
    }
    cout << mn << endl;
    int i = 0;
    while (n--) {
        if (i == mn) i = 0;
        cout << i << ' ';
        i++; 
    }
    cout << endl;
}

int main() {
    speed;
    solve();
    return 0;
}
