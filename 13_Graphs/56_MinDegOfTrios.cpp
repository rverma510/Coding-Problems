#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int minTrioDegree(int n, vector<vector<int>> edges) {
    map<int, int> m;
    for (int i = 1; i <= n; i++) m[i] = 0;
    set<pii> s;
    for (auto e: edges) {
        int u = e[0];
        int v = e[1];
        m[u]++; m[v]++;
        s.insert({u, v});
        s.insert({v, u});
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (s.count({i, j}) && s.count({j, k}) && s.count({k, i})) {
                    ans = min(ans, m[i] + m[j] + m[k] - 6);
                } 
            }
        }
    }
    if (ans == INT_MAX) return -1;
    return ans;
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6}};
    cout << minTrioDegree(n, edges) << '\n';
    return 0; 
}