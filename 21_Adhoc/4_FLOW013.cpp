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
int t, a, b, c;
int main() {
    speed;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if (a + b + c == 180)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}