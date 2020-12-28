/*
ID: raghavv2
LANG: C++14
TASK: beads 
*/
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
const int maxn = 400;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

char ch;
int n;
string str;
int l[maxn * 2][2], r[maxn * 2][2];

void solve() {
    cin >> n; cin.get(ch);
    getline(cin, str);
    str += str;
    l[0][0] = 0;
    l[0][1] = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (str[i - 1] == 'r') {
            l[i][0] = l[i - 1][0] + 1;
            l[i][1] = 0;
        }
        else if (str[i - 1] == 'b') {
            l[i][1] = l[i - 1][1] + 1;
            l[i][0] = 0;
        }
        else {
            l[i][0] = l[i - 1][0] + 1;
            l[i][1] = l[i - 1][1] + 1;
        }
    }
    r[2 * n][0] = 0;
    r[2 * n][1] = 0;
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (str[i] == 'r') {
            r[i][0] = r[i + 1][0] + 1;
            r[i][1] = 0;
        }
        else if (str[i] == 'b') {
            r[i][1] = r[i + 1][1] + 1;
            r[i][0] = 0;
        }
        else {
            r[i][0] = r[i + 1][0] + 1;
            r[i][1] = r[i + 1][1] + 1;
        } 
    } 
    int ans = 0;
    for (int i = 0; i <= 2 * n; i++) {
        ans = max(ans, max(l[i][0], l[i][1]) + max(r[i][0], r[i][1]));
    }
    ans = min(ans, n);
    cout << ans << endl;
}

int main() {
    speed;
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    solve();
    return 0;
}