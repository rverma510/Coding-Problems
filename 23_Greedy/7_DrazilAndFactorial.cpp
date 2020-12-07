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
string s;
map<int, vector<int>> m;

void initialize() {
    m[2] = {2};
    m[3] = {3};
    m[4] = {2, 2, 3};
    m[5] = {5};
    m[6] = {3, 5};
    m[7] = {7};
    m[8] = {2, 2, 2, 7};
    m[9] = {2, 3, 3, 7};
}

void solve() {
    cin >> n; cin.get(ch);
    string s;
    getline(cin, s);
    vector<int> res;
    int i = 0;
    for (auto i: s) {
        if (i == '0' || i == '1') continue;
        for (auto j: m[i - '0']) {
            res.pb(j);
        }
    }
    sort(res.begin(), res.end(), greater<int>());
    for (auto i: res) cout << i;
    cout << endl;
}

int main() {
    speed;
    initialize();
    solve();
    return 0;
}