#include<bits/stdc++.h>
using namespace std;

vector<int> getPath(int **edges, int n, int s, int d, bool *visited) {
    if (s == d) {
        return {s};
    }
    queue<int> q;
    unordered_map<int, int> m;
    q.push(s);
    visited[s] = true;
    vector<int> res;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == d) {
            break;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[v][i]) {
                q.push(i);
                visited[i] = true;
                m.insert({i, v});
            }
        }
    }
    if (visited[d]) {
        res.push_back(d);
        while(m[d] != s) {
            res.push_back(m[d]);
            d = m[d];
        }
        res.push_back(s);
        return res;
    }
    else
        return {};
}

int main() {
    int n, e, s, d;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++) {
        cin>>s>>d;
        edges[s][d] = 1;
        edges[d][s] = 1;
    }
    cin>>s>>d;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    vector<int> res = getPath(edges, n, s, d, visited);
    if (res.size()) {
        for (int i = 0; i < res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited;
    return 0;
}