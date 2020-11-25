#include<bits/stdc++.h>
using namespace std;
int main() {
    int m, s;
    cin >> m >> s;
    if (m == 1 & s == 0) {
        cout << 0 << ' ' << 0 << '\n';
    }
    else if (s >= 1 && s <= 9 * m) {
        vector<short> smallest(m, 0), largest(m, 9);
        smallest[0] = 1;
        int tmp = s - 1, i = m - 1;
        while (i >= 0  && tmp > 0) {
            if (tmp <= 9) {
                smallest[i] += tmp;
                break;
            }
            smallest[i] += 9;
            tmp -= 9;
            i--;
        }
        tmp = 9 * m  - s; i = m - 1;
        while (i >= 0 && tmp > 0) {
            if (tmp <= 9) {
                largest[i] -= tmp;
                break;
            }
            largest[i] -= 9;
            tmp -= 9;
            i--;
        }
        for (auto i: smallest) {
            cout << i;
        }
        cout << ' ';
        for (auto i: largest) {
            cout << i;
        }
        cout << '\n';
    }
    else {
        cout << -1 << ' ' << -1 << '\n';
    }


    return 0;
}