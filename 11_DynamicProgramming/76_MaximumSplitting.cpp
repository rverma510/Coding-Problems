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
const int maxn = 16;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int q, n;
int ans[maxn];

void solve() {
    cin >> n;
    if (n < maxn) {
        cout << ans[n] << endl;
        return;
    }
    int t = (n - maxn) / 4 + 1;
    cout << t + ans[n - 4 * t] << endl;
}

int main() {
    speed;
    mem(ans, -1);
    ans[0] = 0;
    for (int i = 1; i < maxn; i++) {
        for (auto j: vector<int>{4, 6, 9}) {
            if (i >= j && ans[i - j] != -1) {
                ans[i] = max(ans[i], ans[i - j] + 1);
            }
        }
    }
    cin >> q;
    while (q--) solve();
    return 0;
}
