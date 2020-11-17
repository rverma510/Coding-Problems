#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rf freopen("in.txt", "r", stdin);
#define wf freopen("out.txt", "w", stdout);
using namespace std;

typedef long long ll;
const int mx = 2e5 + 10, mod = 1e9 + 7;
int n, a[mx];

int main() {
    speed;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        while (num < a[i]) num = 2 * num + 1;
        for (int j = i - 2, sum = a[i - 1]; j >= 0; j--) {
            if (sum > num) break;
            if (a[i] > a[j] && sum == (a[i] ^ a[j])) ans++;
            sum += a[j];
        }
        for (int j = i + 2, sum = a[i + 1]; j < n; j++) {
            if (sum > num) break;
            if (a[i] > a[j] && sum == (a[i] ^ a[j])) ans++;
            sum += a[j];
        }
    }
    cout << ans << "\n";
    return 0;
}