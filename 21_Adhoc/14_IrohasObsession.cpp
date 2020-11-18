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
const int maxn = 1e4 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

ll n, k;
bool d[10];
set<int> s2;

bool check(ll x) {
    while (x) {
        if (d[x % 10]) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main() {
    speed;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        d[tmp] = true;
    }
    while (true) {
        if (check(n)) {
            cout << n << endl;
            break;
        }
        n++;
    }
    return 0;
}