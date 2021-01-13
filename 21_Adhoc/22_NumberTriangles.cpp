#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 1010;

int n;
int arr[maxn][maxn];

int main() {
    speed;
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = arr[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                arr[i][j] += arr[i - 1][j];
            }
            else if (j == i) {
                arr[i][j] += arr[i - 1][j - 1];
            }
            else {
                arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
            }
            // cout << arr[i][j] << ' ';
            if (i == n - 1) ans = max(ans, arr[i][j]);
        }
        // cout << endl;
    }
    cout << ans << '\n';
    return 0;
}