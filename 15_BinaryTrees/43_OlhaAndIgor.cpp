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

int n, h;
int arr[maxn];
mt19937 rnd(time(0));

int random() {
    return rnd() % n + 1;
}

int ask(int u, int v, int w) {
    cout << "? " << u << ' ' << v << ' ' << w << endl;
    cout.flush();
    cin >> u;
    return u;
}

int main() {
    speed;
    cin >> h;
    n = (1 << h) - 1;
    for (int i = 0; i < 420; i++) {
        int u = random(), v = random(), w = random();
        if (u == v || v == w || w == u) {
            i--;
            continue;
        }
        arr[ask(u, v, w)]++;
    }
    vector<pii> v;
    for (int i = 1; i <= n; i++) {
        v.pb({arr[i], i});
    }
    sort(all(v), greater<pii>());
    int x = v[0].se, y = v[1].se;
    for (int i = 1; i <= n; i++) {
        if (i == x || i == y) continue;
        if (ask(x, y, i) == i) {
            cout << "! " << i << endl;
            cout.flush();
            break;
        }
    }
    return 0;
}