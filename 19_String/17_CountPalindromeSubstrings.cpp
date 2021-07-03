#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int maxPalin(const string &str) {
    int n = str.length();
    int cnt = 0;
    set<pii> s;
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && str[l] == str[r]) {
            s.insert({l, r});
            l--; r++;
        }
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && str[l] == str[r]) {
            s.insert({l, r});
            l--; r++;
        }
    }
    return s.size();
}

int main() {
    string str;
    cin >> str;
    cout << maxPalin(str) << '\n';
    return 0;
}