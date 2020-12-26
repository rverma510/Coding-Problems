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

int t;
map<ll, int> m;

ll find_pat(ll i) {
    string tmp = "";
    if (i == 0) tmp = "0";
    while (i != 0) {
        tmp = tmp + to_string((i % 10) % 2);
        i /= 10;
    }
    reverse(tmp.begin(), tmp.end());
    ll p = stoll(tmp);
    return p;
}

void solve() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        char ch; ll tmp;
        cin >> ch >> tmp;
        ll p = find_pat(tmp);
        if (ch == '+') {
            m[p]++;
        }
        else if (ch == '-') {
            m[p]--;
        }
        else {
            cout << m[p] << endl;
        }
    }
}

int main() {
    speed;
    solve();
    return 0;
}