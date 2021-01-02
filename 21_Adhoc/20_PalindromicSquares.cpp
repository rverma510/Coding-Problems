#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int b;

string convert(int n) {
    string c = "";
    while (n != 0) {
        int tmp = n % b;
        n /= b;
        if (tmp <= 9) c += '0' + tmp;
        else c += ('A' + tmp - 10);
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
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    cin >> b;
    for (int i = 1; i <= 300; i++) {
        string str = convert(i * i);
        if (check_palin(str)) {
            cout << convert(i) << ' ' << str << endl;
        }
    }
    return 0;
}