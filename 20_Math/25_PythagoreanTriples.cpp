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

void solve() {
    cin >> n;
    if (n == 1 || n == 2) {
        cout << -1 << endl;
        return;
    }
    ll a, b;
    if (n & 1) {
        a = (n * n - 1) / 2;
        b = (n * n + 1) / 2;
    }
    else {
        a = (n * n) / 4 - 1;
        b = (n * n) / 4 + 1;
    }
    cout << a << ' ' << b << endl;
}

int main() {
    speed;
    solve();
    return 0;
}
