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
int t, n;
int main() {
    speed;
    t = 1;
    while (t--) {
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            if (tmp & 1) res++;
        }
        if (res >= n - res)
            cout << "NOT READY" << "\n";
        else
            cout << "READY FOR BATTLE" << "\n";
    }
    return 0;
}