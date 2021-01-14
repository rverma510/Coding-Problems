#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 2e2 + 10;
int n;
vector<double> arr[maxn];
int idx[maxn];

int main() {
    speed;
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = n; j > i; j--) {
            if (i != 1 && __gcd(i, j) != 1) continue;
            arr[i].push_back(j);
        }
        idx[i] = 0;
    }
    cout << "0/1\n";
    while (true) {
        double mn = 10;
        int x = -1;
        for (int i = 1; i < n; i++) {
            if (idx[i] < (int)arr[i].size() && mn > (i / arr[i][idx[i]])) {
                mn = (i / arr[i][idx[i]]);
                x = i;
            }
        }
        if (x == -1) break;
        cout << x << '/' << arr[x][idx[x]] << '\n';
        idx[x]++;
    }
    cout << "1/1\n";
    return 0;
}