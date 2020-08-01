#include <bits/stdc++.h>
using namespace std;
void dfsHelper(vector<vector<int>> &graph, int src, vector<bool> &visited) {
    cout << src << " ";
    visited[src] = true;
    for (int i = 0; i < graph[src].size(); i++) {
        int des = graph[src][i];
        if (!visited[des])
            dfsHelper(graph, des, visited);
    }
}
void dfs(vector<vector<int>> &graph) {
    int v = graph.size();
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            dfsHelper(graph, i, visited);
    }
    cout << endl;
}
int main() {
    int v, e, s, d;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for(int i = 0; i < e; i++) {
        cin >> s >> d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }
    dfs(graph);
    return 0;
}