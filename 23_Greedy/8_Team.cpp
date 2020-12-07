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

ll n, m;

void solve() {
    cin >> n >> m;
    if (m < n - 1 || m > 4 + (n - 1) * 2) {
        cout << -1 << endl;
        return;
    }
    if (n > m) {
        cout << "0";
        n--;
    }
    for (int i = 0; i < n; i++) {
        if (m >= n - i + 1) {
            cout << "110";
            m -= 2;
        }
        else {
            cout << "10";
            m--;
        }
    }
    while (m > 0) {
        cout << "1";
        m--;
    } 
}

int main() {
    speed;
    solve();
    return 0;
}