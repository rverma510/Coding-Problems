#include<bits/stdc++.h>
using namespace std;
vector<int> adjList[100010];
bool visited[100010];
stack<int> st;
void dfs(int idx) {
    visited[idx] = true;
    for (int i = 0; i < adjList[idx].size(); i++) {
        int next = adjList[idx][i];
        if (visited[next])
            continue;
        dfs(next);
    }
    st.push(idx);
}

void dfs2(int idx) {
    visited[idx] = true;
    for (int i = 0; i < adjList[idx].size(); i++) {
        int next = adjList[idx][i];
        if (visited[next])
            continue;
        dfs2(next);
    }
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, m, x, y;
        cin>>n>>m;
        vector<int> *edges = new vector<int>[n];
        for (int i = 0; i < m; i++) {
            cin>>x>>y;
            adjList[x - 1].push_back(y - 1);
        }
        memset(visited,false,sizeof(visited));
        for (int i = 0; i < n; i++) {
            if(visited[i])
                continue;
            dfs(i);
        }
        memset(visited,false,sizeof(visited));
        int count = 0;
        while(!st.empty()) {
            int element = st.top();
            st.pop();
            if(visited[element])
                continue;
            count++;
            dfs2(element);
        }
        cout<<count<<endl;
        for(int i = 0; i < n; i++){
            adjList[i].clear();
        }
    }   
}