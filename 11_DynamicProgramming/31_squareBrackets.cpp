#include<bits/stdc++.h>
using namespace std;
int solve(int o, int c, int n, bool *flag, int **mem){
    if(o > n || c > n)
        return 0;
    if(o == n && c == n){
        return 1;
    }
    if(mem[o][c] != -1)
        return mem[o][c];
    if(o == c || flag[o + c])
        mem[o][c] = solve(o + 1, c, n, flag, mem);
    else if(o == n)
        mem[o][c] = solve(o, c + 1, n, flag, mem);
    else{
        mem[o][c] = solve(o + 1, c, n, flag, mem) + solve(o, c + 1, n, flag, mem);
    }
    return mem[o][c];
}
int main(){
    int d;
    cin>>d;
    while(d--){
        int n, k;
        cin>>n>>k;
        bool *flag = new bool[2*n];
        for(int i = 0; i < 2*n; i++)
            flag[i] = false;
        for(int i = 0; i < k; i++){
            int temp;
            cin>>temp;
            flag[temp - 1] = true;
        }
        int **mem = new int*[n + 1];
        for(int i = 0; i <= n; i++){
            mem[i] = new int[n + 1];
            for(int j = 0; j <= n; j++)
                mem[i][j] = -1;
        }
        cout<<solve(0, 0, n, flag, mem)<<endl;   
    }
}