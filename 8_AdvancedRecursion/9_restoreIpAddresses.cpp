

#include <bits/stdc++.h>
using namespace std;

void helper(string s, int idx, int c, string ip, vector<string> & res) {
    if (c > 4) return;
    if (c == 4 && idx == s.size()) {
        res.push_back(ip);
        return;
    }
    for (int i = 1; i < 4; i++) {
        if (idx + i > s.size()) break;
        string t = s.substr(idx, i);
        if ((t.size() > 1 && t[0] == '0') || (stoi(t) >= 256)) continue;
        helper(s, idx + i, c + 1, ip + t + (c == 3 ? "" : "."), res);
    }
    
}
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    helper(s, 0, 0, "", res);
    return res;
}

int main() {
    string s;
    cin >> s;
    vector<string> res = restoreIpAddresses(s);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << '\n';
    }
    return 0;
}