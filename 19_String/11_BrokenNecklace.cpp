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

void solve() {
    cin >> n; cin.get(ch);
    getline(cin, str);
    str += str;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char color = (char)str[i];
        int state;
        if (color == 'w') state = 0;
        else state = 1;
        int j = i, curr = 0;
        while (state <= 2) {
            while (j < n + i && (str[j] == color || str[j] == 'w')) {
                curr++;
                j++;
            }
            state++;
            color = str[j];
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
}

int main() {
    speed;
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    solve();
    return 0;
}