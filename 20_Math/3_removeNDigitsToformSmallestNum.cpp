#include <bits/stdc++.h>
using namespace std;
void insertIntoDeque(deque<char> &d, char ch) {
    if (d.empty()) {
        d.push_back(ch);
    }
    else {
        char tmp = d.back();
        while (tmp > ch && !d.empty()) {
            d.pop_back();
            if (!d.empty())
                tmp = d.back();
        }
        d.push_back(ch);
    }
} 

string smallestNumber(string s, int n) {
    deque<char> d;
    string res = "";
    for (int i = 0; i <= n; i++) {
        insertIntoDeque(d, s[i]);
    }
    for (int i = n + 1; i < s.size(); i++) {
        res += d.front();
        d.pop_front();
        insertIntoDeque(d, s[i]);
    }
    res += d.front();
    return res;
}

int main() {
    string s; cin >> s;
    int n; cin >> n;
    cout << smallestNumber(s, n) << endl;
    return 0;
}