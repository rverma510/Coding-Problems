#include<bits/stdc++.h>
using namespace std;

string solve(int n) {
    vector<int> parent(n, -1), digit(n);
    queue<int> q;
    int rem = 1 % n;
    digit[rem] = 1;
    q.push(rem);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == 0) break;
        int mod0 = (curr * 10) % n;
        int mod1 = (curr * 10 + 1) % n;
        if (parent[mod0] == -1 && mod0 != 1) {
            parent[mod0] = curr;
            digit[mod0] = 0;
            q.push(mod0);
        }
        if (parent[mod1] == -1 && mod1 != 1) {
            parent[mod1] = curr;
            digit[mod1] = 1;
            q.push(mod1);
        }
    }
    string ans = "";
    int i = 0;
    while (i != -1) {
        ans += digit[i] + '0';
        i = parent[i];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}