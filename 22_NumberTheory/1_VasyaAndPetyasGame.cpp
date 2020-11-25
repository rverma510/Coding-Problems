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


int t, n;

bool prime[maxn];
void sieve() {
    mem(prime, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    speed;
    sieve();
    cin >> n;
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) continue;
        int tmp = i;
        while (tmp <= n) {
            ans.pb(tmp);
            tmp *= i;
        }
    }
    cout << ans.size() << endl;
    for (auto i: ans) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}