#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> ppi;
int find(int *parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}
void combine(int *parent, int *rank, int xP, int yP) {
    if (rank[xP] > rank[yP]) {
        parent[yP] = xP;
    }
    else if (rank[xP] < rank[yP]) {
        parent[xP] = yP;
    }
    else {
        rank[xP]++;
        parent[yP] = xP;
    }
}
void kruskal(vector<ppi> edges, int n) {
    sort(edges.begin(), edges.end());
    int count = 0;
    int k = 0;
    vector<ppi> res;
    int *parent = new int[n];
    int *rank = new int[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    while (count < n - 1) {
        if (k >= edges.size())
            break;
        ppi p = edges[k];
        int w = p.first;
        int x = p.second.first;
        int y = p.second.second;
        int xP = find(parent, x);
        int yP = find(parent, y);
        if (xP != yP) {
            res.push_back(edges[k]);
            count++;
            combine(parent, rank, xP, yP);
        }
        k++;
    }
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i].second.first<<" "<<res[i].second.second<<" "<<res[i].first<<endl;
    }
}
int main() {
    int n, e, x, y, w;
    cin>>n>>e;
    vector<ppi> edges;
    for (int i = 0; i < e; i++) {
        cin>>x>>y>>w;
        if (x < y)
        	edges.push_back({w, {x, y}});
    	else 
            edges.push_back({w, {y, x}});
    }
    kruskal(edges, n);
    return 0;
}