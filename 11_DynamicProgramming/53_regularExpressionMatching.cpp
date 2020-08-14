#include <bits/stdc++.h>
using namespace std;

bool recursiveMatching(string s, int i, string p, int j) {
    if (j == p.size()) return i == s.size();
    
    bool isCurrentMatching = i != s.size() && (s[i] == p[j] || p[j] == '.');

    if (j + 1 < p.size() && p[j + 1] == '*') {
        return (isCurrentMatching && recursiveMatching(s, i + 1, p, j)) || 
                recursiveMatching(s, i, p, j + 2);
    }
    else {
        return recursiveMatching(s, i + 1, p, j + 1);
    }
}

int main() {
    string s, p;
    getline(cin, s);
    getline(cin, p);
    cout << recursiveMatching(s, 0, p, 0) << endl;
    return 0;
}