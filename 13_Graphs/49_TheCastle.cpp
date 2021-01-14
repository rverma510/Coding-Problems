#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 5e1 + 10;
char dir;
int n, m, num_comp, mx, comb, x, y;
int arr[maxn][maxn];
int res[maxn][maxn];
unordered_map<int, int> mp;


void fill(int i, int j, int &c) {
    if (i < 0 || j < 0 || i >= n || j >= m || res[i][j] != 0) return;
    res[i][j] = num_comp;
    c++;
    if (!(arr[i][j] & 1)) fill(i, j - 1, c);
    if (!(arr[i][j] & 2)) fill(i - 1, j, c);
    if (!(arr[i][j] & 4)) fill(i, j + 1, c);
    if (!(arr[i][j] & 8)) fill(i + 1, j, c);
}

int main() {
    speed;
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    num_comp = 0;
    mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] == 0) {
                num_comp++;
                int c = 0;
                fill(i, j, c);
                mp[num_comp] = c;
                mx = max(mx, c);
            }
        }
    }
    comb = 0; x = -1; y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j - 1 >= 0 && res[i][j] != res[i][j - 1]) {
                if (comb < mp[res[i][j]] + mp[res[i][j - 1]]) {
                    comb = mp[res[i][j]] + mp[res[i][j - 1]];
                    x = i;
                    y = j;
                    dir = 'W';
                }
                else if (comb == mp[res[i][j]] + mp[res[i][j - 1]]) {
                    if (j < y || (j == y && i > x)) {
                        x = i;
                        y = j;
                        dir = 'W';
                    }
                }
            }
            if (i + 1 < n && res[i][j] != res[i + 1][j]) {
                if (comb < mp[res[i][j]] + mp[res[i + 1][j]]) {
                    comb = mp[res[i][j]] + mp[res[i + 1][j]];
                    x = i;
                    y = j;
                    dir = 'S';
                }
                else if (comb == mp[res[i][j]] + mp[res[i + 1][j]]) {
                    if (j < y || (j == y && i > x)) {
                        x = i;
                        y = j;
                        dir = 'S';
                    }
                }
            }
            if (i - 1 >= 0 && res[i][j] != res[i - 1][j]) {
                if (comb < mp[res[i][j]] + mp[res[i - 1][j]]) {
                    comb = mp[res[i][j]] + mp[res[i - 1][j]];
                    x = i;
                    y = j;
                    dir = 'N';
                }
                else if (comb == mp[res[i][j]] + mp[res[i - 1][j]]) {
                    if (j < y || (j == y && i > x)) {
                        x = i;
                        y = j;
                        dir = 'N';
                    }
                }
            }
            if (j + 1 < m && res[i][j] != res[i][j + 1]) {
                if (comb < mp[res[i][j]] + mp[res[i][j + 1]]) {
                    comb = mp[res[i][j]] + mp[res[i][j + 1]];
                    x = i;
                    y = j;
                    dir = 'E';
                }
                else if (comb == mp[res[i][j]] + mp[res[i][j + 1]]) {
                    if (j < y || (j == y && i > x)) {
                        x = i;
                        y = j;
                        dir = 'E';
                    }
                }
            }
        }
    }
    cout << num_comp << '\n'; 
    cout << mx << '\n';
    cout << comb << '\n';
    cout << x + 1 << ' ' << y + 1 << ' ' << dir << '\n';
    return 0;
}