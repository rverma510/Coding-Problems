#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
int visited = 0;
bool res;
ll curr;
ll tar;

void helper (vector<int>& matchsticks, int j) {
    if (curr >= tar) {
        res = (curr == tar);
        return;
    }
    for (int i = j; i < n; i++) {
        if (visited & (1 << i)) continue;
        visited |= (1 << i);
        curr += matchsticks[i];
        helper(matchsticks, i + 1);
        if (res) return;
        visited ^= (1 << i);
        curr -= matchsticks[i];
    }
}

bool makesquare(vector<int>& matchsticks) {
    sort(matchsticks.begin(), matchsticks.end(), [](int a, int b) { return a > b; });
    n = matchsticks.size();
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matchsticks[i];
    }
    tar = sum / 4;
    if ((sum & 3) || matchsticks[0] > tar) return false;
    for (int i = 0; i < 3; i++) {
        res = false;
        curr = 0;
        helper(matchsticks, 0);
        if (!res) break;
    }
    return res;
}

int main() {
    vector<int> matchsticks1 = {1, 1, 2, 2, 2};
    vector<int> matchsticks2 = {3, 3, 3, 3, 4};
    cout << makesquare(matchsticks1) << '\n';
    cout << makesquare(matchsticks2) << '\n';
    return 0;

}