#include <bits/stdc++.h>
using namespace std;

string zigzagConversion(string s, int num) {
    if (num <= 1)
        return s;
    int n = s.size();
    int jump = num * 2 - 2;
    string res = "";
    for (int i = 0; i < num; i++) {
        int k = jump - i * 2;
        for (int j = i; j < n; j += jump) {
            res += s[j];
            if (k > 0 && k < jump && j + k < n)
                res += s[j + k];
        }
    }
    return res;
}

int main() {
    int num;
    string s;
    cin >> s;
    cin >> num;
    cout << s << " " << num << endl; 
    cout << zigzagConversion(s, num) << endl;
    return 0;
}