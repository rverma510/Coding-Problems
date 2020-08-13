#include <bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string s) {
    int n = s.size(), l, r;
    if (n < 2)
        return s;
    int mx = 0;
    string res = "";
    for (int i = 0; i < n; i++) {
        // odd length
        l = i; r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (mx < r - l + 1) {
                mx = r - l + 1;
                res = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }
        // even length
        l = i; r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (mx < r - l + 1) {
                mx = r - l + 1;
                res = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindromicSubstring(s) << endl;
    return 0;
}