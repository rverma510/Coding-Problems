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
const int maxn = 3;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

ll t, n;

void solve() {
    cin >> n;
    int two = 0, three = 0;
    while (n % 2 == 0) {
        n /= 2;
        two++;
    }
    while (n % 3 == 0) {
        n /= 3;
        three++;
    }
    if ((n != 1) || (two > three)) {
        cout << -1 << endl;
        return;
    }
    cout << 2 * three - two << endl;
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}