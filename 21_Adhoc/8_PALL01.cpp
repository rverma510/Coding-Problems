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
int t, n, m, tmp;
int main() {
    speed;
    cin >> t;
    while (t--) {
        cin >> n;
        tmp = n; m = 0;
        while (tmp) {
            m = m * 10 + tmp % 10;
            tmp /= 10;
        }
        if (n == m)
            cout << "wins\n";
        else
            cout << "loses\n";
    }
    return 0;
}