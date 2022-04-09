// https://leetcode.com/problems/multiply-strings/

#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int n = num2.length();
    int m = num1.length();
    string res[n];
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        res[i] = "";
        for (int j = 0; j < n - 1 - i; j++) {
            res[i] += "0";
        }
        int mul = num2[i] - '0';
        carry = 0;
        for (int j = m - 1; j >= 0; j--) {
            int r = mul * (num1[j] - '0') + carry;
            res[i] += to_string(r % 10);
            carry = r / 10;
        }
        if (carry != 0) {
            res[i] += to_string(carry);
        }
    }
    string ans = "";
    carry = 0;
    int j = 0;
    for (int j = 0; ; j++) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (j >= res[i].length()) continue;
            done = false;
            carry += res[i][j] - '0';
        }
        if (done) {
            break;
        }
        ans += to_string(carry % 10);
        carry /= 10;
    }
    if (carry != 0) {
        ans += to_string(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string num1, num2;
    getline(cin, num1);
    getline(cin, num2);
    cout << multiply(num1, num2) << '\n';
    return 0;
}