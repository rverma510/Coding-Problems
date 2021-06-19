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
const int maxn = 5e4 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool prime[maxn];
int p[maxn];
int cnt{0};

void pre_calc() {
    mem(prime, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < maxn; i++) {
        if (prime[i]) {
            for (int j = i * i; j < maxn; j += i) prime[j] = false;
        }
    }
    for (int i = 2; i < maxn; i++) {
        if (prime[i]) p[cnt++] = i;
    }
}

int t, a, b, k, n, m, g, mx;

void solve() {
    cin >> a >> b >> k;
    g = __gcd(a, b);
    if (a == b) m = 0;
    else if (g == a || g == b) m = 1;
    else m = 2;
    n = 0;
    mx = sqrt(max(a, b)) + 1;
    for (int i = 0; i < cnt; i++) {
        if (p[i] > mx) break;
        while (!(a % p[i])) {
            a /= p[i];
            n++;
        }
        while (!(b % p[i])) {
            b /= p[i];
            n++;
        }
    }
    if (a > 1) n++;
    if (b > 1) n++;
    if (k >= m && k <= n && ((k == 1 && m == 1) || (k != 1))) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    speed;
    pre_calc();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}