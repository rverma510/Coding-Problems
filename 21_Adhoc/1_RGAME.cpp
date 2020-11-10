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
const int mx = 1e5 + 10, mod = 1e9 + 7;
int n, t;
int a[mx];
int suffix[mx];

int main() {
    speed;
    cin >> t;
    while (t--) {
        cin >> n;
        n++;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int power_of_2 = 1;
        for (int i = n; i >= 1; i--) {
            suffix[i] = (1ll * power_of_2 * a[i]) % mod;
            if (i < n)
                suffix[i] = (suffix[i + 1] + suffix[i]) % mod;
            power_of_2 = (power_of_2 << 1) % mod;
        }
        int ans = 0;
        power_of_2 = 1;
        for (int i = 1; i < n; i++) {
            int count_ways = (1ll * power_of_2 * a[i]) % mod;
            count_ways = (1ll * count_ways * suffix[i + 1]) % mod;
            ans = (ans + count_ways) % mod;
            if (i >= 2)
                power_of_2 = (power_of_2 << 1) % mod;
        }
        cout << (2 * ans) % mod << "\n";
    }
    return 0;
}