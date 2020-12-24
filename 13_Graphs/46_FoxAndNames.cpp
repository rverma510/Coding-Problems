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
const int maxn = 1e2 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

char ch;
int n;
string arr[maxn];
bool graph[27][27];
bool vis[27];

int gid(char ch) {
    if (ch == ' ') return 0;
    else return ch - 'a' + 1;
}

void solve() {
    mem(graph, false);
    for (int i = 1; i <= 26; i++) graph[0][i] = true;
    cin >> n; cin.get(ch);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] += " ";
    }
    for (int i = 0; i < n - 1; i++) {
        int j = 0,sz = min(arr[i].size(), arr[i + 1].size());
        while(j < sz && arr[i][j] == arr[i + 1][j]) j++;
        if (j == sz) continue;
        graph[gid(arr[i][j])][gid(arr[i + 1][j])] = true;
    }
    for (int k = 0; k <= 26; k++) {
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                graph[i][j] |= graph[i][k] & graph[k][j];
            }
        }
    }
    bool cycle = false;
    for (int i = 0; i <= 26; i++) cycle |= graph[i][i];
    if (cycle) {
        cout << "Impossible\n";
        return;
    }
    else {
        for (int i = 0; i <= 26; i++) {
            int now = 0;
            for (int j = 0; j <= 26; j++) {
                bool valid = !vis[j];
                for (int k = 0; k <= 26; k++) {
                    if (!vis[k] && graph[k][j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    now = j;
                    break;
                }
            }
            if (i > 0) cout << char('a' + now - 1);
            vis[now] = true;
        }
        cout << endl;
    }
}

int main() {
    speed;
    solve();
    return 0;
}