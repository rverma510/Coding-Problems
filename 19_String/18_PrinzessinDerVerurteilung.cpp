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
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;

const double pi = acos(-1.0);
const int maxn = 1e6 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ld scale = 1e6;

int t, n;
string s;
string ans[20010];
int cnt{0};

void helper() {
    for (int i = 1; i <= 3; i++) {
        string st(i, 'a');
        string en(i, 'z');
        while (true) {
            int j;
            for (j = 0; j < 25; j++) {
                ans[cnt++] = st;
                st[i - 1]++;
            }
            ans[cnt++] = st;
            if (st == en) break;
            j = i - 1;
            while (j > 0 && st[j] == 'z') {
                st[j] = 'a';
                j--;
            }
            st[j]++;
        }
    }
}

void solve() {
    cin >> n >> s;
    set<string> se;
    for (int i = 0; i < n; i++) {
        string tmp;
        for (int j = 0; j < 3 && i + j < n; j++) {
            tmp.pb(s[i + j]);
            se.insert(tmp);
        }
    }
    for (int i = 0; i < cnt; i++) {
        if (se.find(ans[i]) == se.end()) {
            cout << ans[i] << '\n';
            return; 
        }
    }
}

int main() {
    speed;
    helper();    
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}