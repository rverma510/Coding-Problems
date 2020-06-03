#include<bits/stdc++.h>
using namespace std;
int minDistance(int *distance, bool *visited, int n) {
    int min = INT_MAX, minIdx = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && min > distance[i]) {
            min = distance[i];
            minIdx = i;
        }
    }
    return minIdx;
}
void dijkstra(int **edges, int n, int src) {
    int *distance = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[src] = 0;
    for (int c = 0; c < n - 1; c++) {
        int v = minDistance(distance, visited, n);
        visited[v] = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[v][i] && distance[i] > edges[v][i] + distance[v]) {
                distance[i] = edges[v][i] + distance[v];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<i<<" "<<distance[i]<<endl;
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
    dijkstra(edges, n, 0);
    return 0;
}