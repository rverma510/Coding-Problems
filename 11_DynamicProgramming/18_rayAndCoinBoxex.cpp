#include <bits/stdc++.h>
using namespace std;
int* solve(int *box, int *st, int *en, int n){
    box[0] = st[0];
    for(int i = 1; i < n; i++){
        box[i] = st[i] - en[i - 1] + box[i - 1];
    }
    delete [] st;
    delete [] en;
    int *coins = new int[1000001];
    for(int i = 0; i < 1000001; i++){
        coins[i] = 0;
    }
    for(int i = 0; i < n; i++){
        coins[box[i]]++;
    }
    for(int i = 999999; i >= 0; i--){
        coins[i] += coins[i + 1];
    }
    return coins;
}
int main(){
    int n, m, q;
    cin>>n>>m;
    int *box = new int[n];
    int *st = new int[n];
    int *en = new int[n];
    for(int i = 0; i < n; i++){
        box[i] = 0;
        st[i] = 0;
        en[i] = 0;
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin>>x>>y;
        st[x - 1]++;
        en[y - 1]++;
    }
    int *coins = solve(box, st, en, n);
    cin>>q;
    for(int i = 0; i < q; i++){
        int temp;
        cin>>temp;
        cout<<coins[temp]<<endl;
    }
    delete [] box;
    delete [] coins;
    return 0;
}
