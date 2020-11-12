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
int t;
char ch;
map<char, string> m;
void store_ship() {
    m['B'] = m['b'] = "BattleShip";
    m['C'] = m['c'] = "Cruiser";
    m['D'] = m['d'] = "Destroyer";
    m['F'] = m['f'] = "Frigate";
}
int main() {
    speed;
    store_ship();
    cin >> t;
    while (t--) {
        cin >> ch;
        cout << m[ch] << "\n";
    }
    return 0;
}