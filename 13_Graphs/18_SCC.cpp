#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> *edges, int start, unordered_set<int> &visited, stack<int> &finishStack) {
    visited.insert(start);
    for (int i = 0; i < edges[start].size(); i++) {
        int next = edges[start][i];
        if (visited.count(next) == 0) {
            dfs(edges, next, visited, finishStack);
        }
    }
    finishStack.push(start);
}
void dfs2(vector<int> *edges, int start, unordered_set<int> *component, unordered_set<int> &visited) {
    component -> insert(start);
    visited.insert(start);
    for (int i = 0; i < edges[start].size(); i++) {
        int next = edges[start][i];
        if (visited.count(next) == 0) {
            dfs2(edges, next, component, visited);
        }
    }
}
unordered_set<unordered_set<int>*>* getSCC(vector<int> *edges, vector<int> *edgesT, int n){
    unordered_set<int> visited;
    stack<int> finishedVertices;
    for (int i = 0; i < n; i++) {
        if (visited.count(i) == 0) {
            dfs(edges, i, visited, finishedVertices);
        }
    }
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    visited.clear();
    while (finishedVertices.size() != 0) {
        int element = finishedVertices.top();
        finishedVertices.pop();
        if (visited.count(element) != 0)
            continue;
        unordered_set<int> *component = new unordered_set<int>();
        dfs2(edgesT, element, component, visited);
        output -> insert(component);
    }
    return output;
}

int main() {
    int n, m, x, y;
    cin>>n;
    vector<int> *edges = new vector<int>[n];
    vector<int> *edgesT = new vector<int>[n];
    cin>>m;
    for (int i = 0; i < m; i++) {
        cin>>x>>y;
        edges[x - 1].push_back(y - 1);
        edgesT[y - 1].push_back(x - 1);
    }
    unordered_set<unordered_set<int>*>* components = getSCC(edges, edgesT, n);
    unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
    while (it1 != components -> end()) {
        unordered_set<int> *component = *it1;
        unordered_set<int>::iterator it2 = component -> begin();
        while (it2 != component -> end()) {
            cout<<*it2 + 1<<" ";
            it2++;
        }
        cout<<endl;
        delete component;
        it1++;
    }
    delete components;
    delete [] edges;
    delete [] edgesT;
    return 0;
}