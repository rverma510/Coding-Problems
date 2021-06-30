#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ull n;
        cin >> n;
        int m;
        cin >> m;
        ull res = 1;
        if ((n / m) % 2) res = (m - 1);
        n = n % m;
        for (int i = 1; i <= n; i++) {
            res = (res * i) % m;
        }
        cout << res << '\n';
    }
	return 0;
}