// https://leetcode.com/problems/count-and-say/

#include <bits/stdc++.h>
using namespace std;

string modifyString(string res) {
    string ans = "";
    int cnt = 1;
    int n = res.length();
    for (int i = 1; i < n; i++) {
        if (res[i] == res[i - 1]) {
            cnt++;
        }
        else {
            ans += to_string(cnt) + res[i - 1];
            cnt = 1;
        }
    }
    ans += to_string(cnt) + res[n - 1];
    return ans;
}

string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }
    string res = countAndSay(n - 1);
    return modifyString(res);
}

int main() {
    int n;
    cin >> n;
    cout << countAndSay(n) << '\n';
    return 0;
}