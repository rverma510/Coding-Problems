/*
ID: raghavv2
LANG: C++14
TASK: combo
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int f[3], m[3];

int mod(int i) {
    while (i < 0) i += n;
    return i % n;
} 

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    cin >> n;
    cin >> f[0] >> f[1] >> f[2]; f[0]--; f[1]--; f[2]--;
    cin >> m[0] >> m[1] >> m[2]; m[0]--, m[1]--, m[2]--;
    int a{1}, b{1}, anb{1};
    set<int> s1, s2, s3;
    for (int cnt = 0; cnt < 3; cnt++) {
        s1.clear();
        s2.clear();
        s3.clear();
        for (int tmp, i = -2; i <= 2; i++) {
            tmp = mod(f[cnt] + i); s1.insert(tmp);
            tmp = mod(m[cnt] + i); s2.insert(tmp); 
        }
        for (auto i: s1) {
            if (s2.find(i) != s2.end()) s3.insert(i); 
        }
        a *= (int) s1.size();
        b *= (int) s2.size();
        anb *= (int) s3.size();
    }
    cout << a + b - anb << endl;
}