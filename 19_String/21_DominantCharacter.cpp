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

int add(int x, int y) {
    x += y;
    while (x >= mod) {
        x -= mod;
    }
    while (x < 0) {
        x += mod;
    }
    return x;
}

int sub(int x, int y) {
    if (x - y < 0) {
        return x - y + mod;
    }
    return x - y;
}

int mul(int x, int y) {
    return (x * 1ll * y) % mod;
}

int power(int x, int y, int p) {
    int res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * 1ll * x) % p;
        }
        x = (x * 1ll * x) % p;
        y /= 2;
    }
    return res;
}

int fact[maxn], invfact[maxn];
void init() {
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < maxn; i++) {
        fact[i] = (fact[i - 1] * 1ll * i) % mod;
    }
    i--;
    invfact[i] = power(fact[i], mod - 2, mod);
    for (i--; i >= 0; i--) {
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % mod;
    }
}

int ncr(int n, int r) {
    if (r < 0 || n < 0 || r > n)
        return 0;
    return mul(fact[n], mul(invfact[n - r], invfact[r]));
}

int t, n;
string s;

void solve() {
    cin >> n >> s;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        vector<int> cnt(3, 0);
        cnt[s[i] - 'a']++;
        for (int j = i + 1; j < min(n, i + 7); j++) {
            cnt[s[j] - 'a']++;
            if (cnt[0] > cnt[1] && cnt[0] > cnt[2]) {
                res = min(res, j - i + 1);
                break;
            }
        }
    }
    if (res == INT_MAX) res = -1;
    cout << res << endl;
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}