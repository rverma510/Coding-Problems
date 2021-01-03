#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int n, s;

string convert(int i, int b) {
    string c = "";
    while (i != 0) {
        c += "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i % b];
        i /= b;
    }
    reverse(c.begin(), c.end());
    return c;
}

bool check_palin(string str) {
    int sz = str.length();
    for (int i = 0; i < sz / 2; i++) {
        if (str[i] != str[sz - i - 1]) return false;
    }
    return true;
}

int main() {
    // freopen("dualpal.in", "r", stdin);
    // freopen("dualpal.out", "w", stdout);
    cin >> n >> s;
    int i{s + 1};
    while (n > 0) {
        int cnt{0};
        for (int b = 2; b <= 10; b++) {
            string str = convert(i, b);
            
            if (check_palin(str)) cnt++;
        }
        if (cnt >= 2) {
            cout << i << '\n';
            n--;
        } 
        i++;
    }
    return 0;
}