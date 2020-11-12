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
const int mx = 1e4 + 10, mod = 1e9 + 7;
int t, n, m, x, y, s;
int sum_x, sum_y, pre;

int main() {
    speed;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin >> x >> y >> s;
        sum_x = 0; pre = 1;
        for (int i = 0; i < x; i++) {
            int tmp; cin >> tmp;
            sum_x += (tmp - pre) / s;
            pre = tmp + 1;
        }
        sum_x += (n - pre + 1) / s;
        sum_y = 0; pre = 1;
        for (int i = 0; i < y; i++) {
            int tmp; cin >> tmp;
            sum_y += (tmp - pre) / s;
            pre = tmp + 1;
        }
        sum_y += (m - pre + 1) / s;
        cout << sum_x * sum_y << "\n";
    }
    return 0;
}