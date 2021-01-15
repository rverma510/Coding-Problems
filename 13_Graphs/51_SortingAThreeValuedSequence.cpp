#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 1e3 + 10;
int n, one{0}, two{0}, three{0};
bool arr[4][maxn];

int main() {
    speed;
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    cin >> n;
    for (int tmp, i = 0; i < n; i++) {
        cin >> tmp;
        arr[tmp][i] = 1;
        if (tmp == 1) one++;
        else if (tmp == 2) two++;
        else three++;
    }
    int ans = 0;
    // for sorting 1s
    for (int i = 0; i < one; i++) {
        if (arr[1][i]) continue;
        ans++;
        arr[1][i] = 1;
        if (arr[2][i]) {
            arr[2][i] = 0;
            for (int j = one; j < n; j++) {
                if (arr[1][j]) {
                    arr[1][j] = 0;
                    arr[2][j] = 1;
                    break;
                }
            }
        }
        else {
            arr[3][i] = 0;
            for (int j = n - 1; j >= one; j--) {
                if (arr[1][j]) {
                    arr[1][j] = 0;
                    arr[3][j] = 1;
                    break;
                }
            }
        }
    }

    // for sorting 2s
    for (int i = one; i < one + two; i++) {
        if (arr[2][i]) continue;
        ans++;
        arr[2][i] = 1;
        arr[3][i] = 0;
        for (int j = n - 1; j >= one + two; j--) {
            if (arr[2][j]) {
                arr[2][j] = 0;
                arr[3][j] = 1;
                break;
            }
        }
    }
    cout << ans << '\n';
}