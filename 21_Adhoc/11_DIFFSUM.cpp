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
const int mx = 1e5 + 10;
int n, m;
int main() {
    speed;
    cin >> n >> m;
    if (n > m)
        cout << (n - m) << "\n";
    else
        cout << (n + m) << "\n";
    return 0;
}