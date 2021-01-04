#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
bool arr[10];

bool check(int num, int sz) {
    while (num != 0) {
        if (!arr[num % 10]) return false;
        num /= 10;
        sz--;
    }
    if (sz) return false;
    return true;
}

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    cin >> n;
    for (int tmp, i = 0; i < n; i++) {
        cin >> tmp;
        arr[tmp] = 1;
    }
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = 10; j < 100; j++) {
            if (!check(i, 3) || !check(j, 2) || !check(i * j, 4)) continue;
            int m = j;
            while (m != 0) {
                if (!check(i * (m % 10), 3)) break;
                m /= 10;
            }
            if (m == 0) ans++;
        }
    }
    // for (int i = 0; i < 10; i++) {
    //     if (!arr[i] || arr[i] == 0) continue;
    //     for (int j = 0; j < 10; j++) {
    //         if (!arr[j]) continue;
    //         for (int k = 0; k < 10; k++) {
    //             if (!arr[k]) continue;
    //             int num = i * 100 + j * 10 + k;
    //             for (int a = 0; a < 10; a++) {
    //                 if (!arr[a] || arr[a] == 0 || !check(num * a, 3)) continue;
    //                 int prod1 = num * a;
    //                 for (int b = 0; b < 10; b++) {
    //                     if (!arr[b] || !check(num *b, 3)) continue;
    //                     int prod2 = num * b;
    //                     if (check(prod1 * 10 + prod2, 4)) {
    //                         // cout << prod1 << endl << prod2 << endl << prod1 * 10 + prod2 << endl; 
    //                         ans++;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    cout << ans << endl;
}