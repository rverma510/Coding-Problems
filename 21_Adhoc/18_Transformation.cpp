#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int maxn = 20;

int n;
char arr1[maxn][maxn];
char arr2[maxn][maxn];
char res[maxn][maxn];
char tmp[maxn][maxn];


void rotate(int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k == 1) tmp[j][n - i - 1] = arr1[i][j];
            else tmp[j][n - i - 1] = arr2[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k == 1) arr1[i][j] = tmp[i][j];
            else arr2[i][j] = tmp[i][j];
        }
    }
}

bool compare(int k, bool rot) {
    if (rot) rotate(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k == 1 && arr1[i][j] != res[i][j]) return false;
            if (k == 2 && arr2[i][j] != res[i][j]) return false;
        }
    }
    return true;
}

void solve() {
    if (compare(1, true)) {
        cout << 1 << '\n';
    }
    else if (compare(1, true)) {
        cout << 2 << '\n';
    }
    else if (compare(1, true)) {
        cout << 3 << '\n';
    }
    else if (compare(2, false)) {
        cout << 4 << '\n';
    }
    else if (compare(2, true) || compare(2, true) || compare(2, true)) {
        cout << 5 << '\n';
    }
    else if (compare(1, true)) {
        cout << 6 << '\n';
    }
    else {
        cout << 7 << '\n';
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int  j = 0; j < n; j++) {
            cin >> arr1[i][j];
            arr2[i][n - j - 1] = arr1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int  j = 0; j < n; j++) {
            cin >> res[i][j];
        }
    }
    solve();
    return 0;
}

/*

6 
-@-@-@ 
@-@-@- 
-@-@-@ 
@-@-@- 
-@-@-@ 
@-@-@- 
@-@-@- 
-@-@-@ 
@-@-@- 
-@-@-@ 
@-@-@- 
-@-@-@ 



3 
@@@ 
--- 
@@@ 
@@@ 
--- 
@@@
*/