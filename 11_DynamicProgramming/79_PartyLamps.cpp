#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int n, c, tmp;
set<string> res;
unordered_set<int> _on, _off;

bool check(string l) {
    for (int i = 0; i < (int)l.size(); i++) {
        if (l[i] == '1' && _off.find(i + 1) != _off.end()) return false;
        if (l[i] == '0' && _on.find(i + 1) != _on.end()) return false;
    }
    return true;
}

string convert(string l, int op) {
    int m = (int) l.size();
    if (op == 0) {
        for (int i = 0; i < m; i++) {
            if (l[i] == '1') l[i] = '0';
            else l[i] = '1';
        }
    }
    else if (op == 1) {
        for (int i = 0; i < m; i += 2) {
            if (l[i] == '1') l[i] = '0';
            else l[i] = '1';
        }
    }
    else if (op == 2) {
        for (int i = 1; i < m; i += 2) {
            if (l[i] == '1') l[i] = '0';
            else l[i] = '1';
        }
    }
    else {
        for (int i = 0; i < m; i += 3) {
            if (l[i] == '1') l[i] = '0';
            else l[i] = '1';
        }
    }
    return l;
}

void solve(string lamps, int cnt) {
    if (check(lamps)) res.insert(lamps);
    if (cnt == 0) return;
    for (int i = 0; i < 4; i++) {
        string tmp = convert(lamps, i);
        solve(tmp, cnt - 1);
    }
}

int main() {
    speed;
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    cin >> n >> c;
    // on config
    cin >> tmp;
    while (tmp != -1) {
        _on.insert(tmp);
        cin >> tmp;
    }
    // off config
    cin >> tmp;
    while (tmp != -1) {
        _off.insert(tmp);
        cin >> tmp;
    }
    c = c <= 4 ? c : 4;
    string lamps(n, '1');
    solve(lamps, c);
    if (res.empty()) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (auto i: res) cout << i << '\n';
    }
    return 0;
}