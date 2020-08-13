#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int myAtoi(string str) {
    ll res = 0;
    bool isPositive = true;
    int i = 0;
    while (i < str.size() && str[i] == ' ') i++;
    if (i < str.size()) {
        if (str[i] == '+') {
            isPositive = true;
            i++;
        }
        else if (str[i] == '-') {
            isPositive = false;
            i++;
        }   
    }
    while (i < str.size()) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + (str[i] - '0');
            if (!isPositive && res > (ll)INT_MAX + 1) {
                res = INT_MIN;
                break;
            }
            else if (isPositive && res > INT_MAX) {
                res = INT_MAX;
                break;
            }
        }
        else {
            break;
        }
        i++;
        
    }
    return isPositive ? res : -1 * res;
}

int main() {
    string s;
    cin >> s;
    cout << myAtoi(s) << endl;
    return 0;
}