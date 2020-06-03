#include<bits/stdc++.h>
using namespace std;
int minWeight(int *weights, bool *visited, int n) {
    int min = INT_MAX, minIdx = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && min > weights[i]) {
            min = weights[i];
            minIdx = i;
        }
    }
    return minIdx;
}
void prims(int **edges, int n, int src) {
    int *weights = new int[n];
    int *parent = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        weights[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }
    weights[src] = 0;
    for (int c = 0; c < n - 1; c++) {
        int v = minWeight(weights, visited, n);
        if (v == -1)
            break;
        visited[v] = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[v][i] && weights[i] > edges[v][i]) {
                weights[i] = edges[v][i];
                parent[i] = v;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == src)
            continue;
        if (parent[i] < i)
        	cout<<parent[i]<<" "<<i<<" "<<edges[parent[i]][i]<<endl;
        else
            cout<<i<<" "<<parent[i]<<" "<<edges[parent[i]][i]<<endl;
    }
}
int main() {
    int n, e, s, d, w;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++) {
        cin>>s>>d>>w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    prims(edges, n, 0);
    return 0;
}