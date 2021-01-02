#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

string n;
set<string> s;

bool solve(int i, string str) {
    if (i == n.length()) {
        if (s.find(str) != s.end()) {
            cout << str << '\n';
            return true;
        }
        else return false;
    }
    bool ans = false;
    for (int j = 0; j < 3; j++) {
        char ch = 'A' + j + (n[i] - '2') * 3;
        if (ch >= 'Q') ch += 1;
        string tmp = str;
        tmp += ch;
        ans |= solve(i + 1, tmp);
    }
    return ans;
}

int main() {
    ifstream myfile("dict.txt");
    string line;
    while (getline(myfile, line)) {
        s.insert(line);
    }
    myfile.close();
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    getline(cin, n);
    if (!solve(0, "")) cout << "NONE\n";
    return 0;
}