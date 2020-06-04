#include<bits/stdc++.h>
using namespace std;

stack<int> st;
vector<int> adjList[5010];
vector<int> adjListT[5010];
bool visited[5010];
int n, e;

void dfs1(int source) {
    visited[source] = true;
    for (int i = 0; i < adjList[source].size(); i++) {
        int next = adjList[source][i];
        if (visited[next])
            continue;
    	dfs1(next);
    }
    st.push(source);
}

void dfs2(int source, unordered_set<int> *component) {
    visited[source] = true;
    component -> insert(source);
    for (int i = 0; i < adjListT[source].size(); i++) {
        int next = adjListT[source][i];
        if (visited[next])
            continue;
    	dfs2(next, component);
    }
}
 
unordered_set<unordered_set<int>*>* getSCC() {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (visited[i])
			continue;
    	dfs1(i);
    }
    memset(visited, false, sizeof(visited));
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    while (!st.empty()) {
        int ele = st.top();
        st.pop();
        if (visited[ele])
            continue;
        unordered_set<int>* component = new unordered_set<int>();
        dfs2(ele, component);
        output -> insert(component);
    }
    return output;
}

int main() {
    int x, y;
 	while (true) {
        cin>>n;
        if (n == 0)
            break;
    	cin>>e;
        for (int i = 0; i < e; i++) {
            cin>>x>>y;
            adjList[x - 1].push_back(y - 1);
            adjListT[y - 1].push_back(x - 1);
        }
        unordered_set<unordered_set<int>*>* output = getSCC();
        unordered_set<unordered_set<int>*>::iterator it1 = output -> begin();
        while (it1 != output -> end()) {
            bool flag = true;
            unordered_set<int> *component = *it1;
            unordered_set<int>::iterator it2 = component -> begin();
            set<int> res;
            while (it2 != component -> end()) {
                int u = *it2;
                res.insert(u + 1);
                for (int i = 0; i < adjList[u].size(); i++) {
                    int v = adjList[u][i]; 
                    if (component -> count(v) == 0) {
                        flag = false;
                        res.clear();
                        break;
                    }
                }
                if (!flag)
                    break;
                it2++;
            }
            if (flag) {
                for (auto r: res) {
                    cout<<r<<" ";
                }
            }
            delete component;
            it1++;
        }
        cout<<endl;
        delete output;
        for (int i = 0; i < n; i++) {
            adjList[i].clear();
            adjListT[i].clear();
        }
    }
	
	return 0;
}
