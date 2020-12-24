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
const int maxn = 1e5 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

char ch;
int n, cnt;
string str;
map<char, int> m;

void solve() {
    cin >> n; cin.get(ch);
    getline(cin, str);
    for (auto i: str) m[i]++;
    cnt = m.size();
    m.clear();
    int st = 0, e = 0;
    m[str[st]]++;
    int ans = INT_MAX;
    while (e < str.size()) {
        e++;
        m[str[e]]++;
        while (m.find(str[st]) != m.end() && m[str[st]] > 1) {
            m[str[st]]--;
            st++;
        }
        if (m.size() == cnt && ans > e - st + 1) ans = e - st + 1;
    }
    ans = min(ans, e - st);
    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}