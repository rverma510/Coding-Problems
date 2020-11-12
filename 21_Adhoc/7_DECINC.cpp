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
        if (n % 4)
            cout << n - 1 << "\n";
        else
            cout << n + 1 << "\n";
    }
    return 0;
}