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

int t, n, k;

int helper(int a, int b, int k) {
    int ans = 0;
    int p = 1;
    while (a > 0 || b > 0) {
        int x = a % k; a /= k;
        int y = b % k; b /= k;
        int z = (x - y + k) % k;
        ans = ans + p * z;
        p = p * k; 
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << 0 << endl;
        }
        else {
            if (i % 2) cout << helper(i - 1, i - 2, k) << endl;
            else cout << helper(i - 2, i - 1, k) << endl;
        }
        int r;
        cin >> r;
        if (r == 1) return;
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