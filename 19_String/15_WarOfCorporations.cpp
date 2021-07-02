#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 1e6 + 10;
int lps[maxn];
void lpsHelper(string pat) {
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < pat.length()) {
        if (pat[i] == pat[j]) {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else {
            if (j == 0) {
                lps[i] = 0;
                i++;
            }
            else {
                j = lps[j - 1];
            }
        }
    }
} 

int KMP(string text, string pat) {
    lpsHelper(pat);
    int n = text.length();
    int m = pat.length();
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (pat[j] == text[i]) {
            i++;
            j++;
        }
        else {
            if (j == 0) {
                i++;
            }
            else {
                j = lps[j - 1];
            }
        }
        if (j == m) {
            text[i - 1] = '#';
            j = 0;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string text, pat;
    cin >> text >> pat;
    cout << KMP(text, pat) << '\n';
    return 0;
}