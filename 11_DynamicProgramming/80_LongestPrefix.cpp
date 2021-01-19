/*
ID: raghavv2
LANG: C++14
TASK: prefix
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 2e5 + 10;

int n, m, best{0};
vector<string> pri[26];
string s;
bool dp[maxn];

bool check(string p, int j) {
    for (int i = 0; i < p.length(); i++) {
        if (j + i >= n || p[i] != s[j + i]) return false;
    }
    return true;
}

// int solve(int n) {
//     int idx = s[n] - 'A';
//     if (n >= s.length() || pri[idx].empty()) return 0;
//     if (dp[n] != -1) return dp[n];
//     int ans = 0;
//     for (int i = 0; i < pri[idx].size(); i++) {
//         int m = pri[idx][i].length();
//         if (check(pri[idx][i], n)) {
//             ans = max(ans, m + solve(n + m));
//         }
//     }   
//     return dp[n] = ans;

// }

int main() {
    // speed;
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    string line;
    if (!fin.is_open() || !fout.is_open()) exit(1);
    while (getline(fin, line)) {
        if (line == ".") break;
        istringstream str(line);
        string tmp;
        while (str >> tmp) {
            int idx = tmp[0] - 'A';
            pri[idx].push_back(tmp);
        }
    }
    s = "";
    while(getline(fin, line)) {
        s += line;
    }
    n = (int) s.length();
    fin.close();
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'A';
        if (dp[i]) {
            best = i;
            for (int j = 0; j < (int)pri[idx].size(); j++) {
                int m = pri[idx][j].length();
                if (check(pri[idx][j], i)) {
                    dp[i + m] = 1;
                }
            }
        }
    }
    // for (int i = 0; i < maxn; i++) {
    //     if (dp[i]) cout << i << ' ';
    // }
    if (dp[s.length()]) best = s.length();
    // fout << solve(0) << '\n';
    fout << best << '\n';
    fout.close();
    return 0;
}