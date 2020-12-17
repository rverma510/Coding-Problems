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
const int maxn = 1e3 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int k;
ll arr[maxn];
ll comb[maxn][maxn];
void solve() {
    cin >> k;
    for (int i = 0; i < k; i++) cin >> arr[i];
    ll res = 1;
    int total = 0;
    for (int i = 0; i < k; i++) {
        res = (res * comb[total + arr[i] - 1][arr[i] - 1] * 1ll) % mod;
        total += arr[i];
    }
    cout << res << endl;
}


int main() {
    speed;
    comb[0][0] = 1;
    for (int i = 1; i < maxn; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
        }
    }
    solve();
    return 0;
}