#include <bits/stdc++.h>
using namespace std;

#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

typedef long long ll;
typedef pair<short, int> psi;

const int maxn = 1e7 + 10, mod = 1e9 + 7;
int n;
int dp[maxn][4];

int add(int x, int y) {
    x += y;
    while (x >= mod) {
        x -= mod;
    }
    while (x < 0) {
        x += mod;
    }
    return x;
}

int main() {
    speed;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0) {
                if (j == 0) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
            else {
                dp[i][j] = add(dp[i - 1][(j + 1) % 4], add(dp[i - 1][(j + 2) % 4], dp[i - 1][(j + 3) % 4])); 
            }
        }
    }
    cout << dp[n][0];
    return 0;
}