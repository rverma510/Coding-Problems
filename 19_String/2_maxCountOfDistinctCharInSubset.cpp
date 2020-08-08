#include <bits/stdc++.h>
using namespace std;

int getMaxCount(string s) {
    int n = s.size();
    vector<bool> count(300, false);
    int i{0}, j{0};
    int ans = 1;
    count[s[i]] = 1;
    while (i < n - 1 && j < n - 1) {
        if (count[s[j + 1]] == true) {
            ans = max(ans, j - i + 1);
            count[s[i]] = false;
            i++;
        }
        else {
            j++;
            count[s[j]] = true;
        }
    }
    ans = max(ans, j - i + 1);
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << getMaxCount(s) << endl;
    return 0;
}