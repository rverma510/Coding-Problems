#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int find(int i, vector<int> &parent) {
    if (i != parent[i])
        parent[i] = find(parent[i], parent);
    return parent[i];
}

void union_(int x, int y, vector<int> &parent, vector<int> &rank) {
    if (rank[x] > rank[y]) {
        parent[y] = x;
    }
    else if (rank[x] < rank[y]) {
        parent[x] = y;
    }
    else {
        rank[x]++;
        parent[y] = x;
    }
}

int solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), compare);
    int sum = 0;
    vector<int> parent(A);
    for(int i = 0; i < A; i++)
        parent[i] = i;
    vector<int> rank(A, 0);
    int count = 0;
    int k = 0;
    while (count < A - 1) {
        cout << B[k][0] << B[k][1] << endl;
        int par_x = find(B[k][0], parent);
        int par_y = find(B[k][1], parent);
        if (par_x != par_y) {
            sum += B[k][2];
            count++;
            union_(par_x, par_y, parent, rank);
        }
        k++;
    }   
    return sum;
}
int main() {
    int s, d, w;
    int A, B;
    cin>>A>>B;
    vector<vector<int>> edges;
    for (int i = 0; i < B; i++) {
        cin>>s>>d>>w;
        edges.push_back({s, d, w});
    }
    cout << solve(A, edges) << endl;
    return 0;
}

/*

4 4
1 2 1
2 3 2
3 4 4
1 4 3

*/
