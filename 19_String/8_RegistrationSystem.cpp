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

char ch;
int n;
map<string, vector<int>> m;

void solve() {
    cin >> n; cin.get(ch);
    for (int i = 0; i < n; i++) {
        string s; getline(cin, s);
        if (m.find(s) == m.end()) {
            m[s] = {0};
            cout << "OK" << endl;
        }
        else {
            int tmp = m[s][m[s].size() - 1] + 1;
            m[s].pb(tmp);
            s = s + to_string(tmp);
            cout << s << endl;
        }
    }
}

int main() {
    speed;
    solve();
    return 0;
}