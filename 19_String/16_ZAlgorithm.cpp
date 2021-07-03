#include <bits/stdc++.h>
using namespace std;

void buildZ(int *Z, string str) {
    int n = str.length();
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = i;
            r = i;
            while (r < n && str[r - l] == str[r]) r++;
            Z[i] = r - l; 
            r--;
        }
        else {
            int k = i - l;
            if (Z[k] < r - i + 1) {
                Z[i] = Z[k];
            }
            else {
                l = i;
                while (r < n && str[r - l] == str[r]) r++;
                Z[i] = r - l;
                r--;
            }
        }
    }
}

void searchString(string text, string pat) {
    string str = pat + "$" + text;
    int n = str.length();
    int *Z = new int[n]{};
    buildZ(Z, str);
    for (int i = pat.length() + 1; i < n; i++) {
        if (Z[i] == pat.length()) {
            cout << i - pat.length() - 1 << ' ';
        }
    }
    delete [] Z;
}

int main() {
    string text = "yabcagazuabcbdfc";
    string pat = "abc";
    searchString(text, pat);
    return 0;
}