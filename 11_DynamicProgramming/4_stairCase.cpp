#include<bits/stdc++.h>
using namespace std;
int stairCase(int n, int *mem){
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    if(mem[n] != -1)
        return mem[n];
    mem[n] = stairCase(n - 1, mem) + stairCase(n - 2, mem) + stairCase(n - 3, mem);
    return mem[n];
}
int stairCase(int n){
    int *mem = new int[n + 1];
    for(int i = 0; i < n + 1; i++)
        mem[i] = -1;
    return stairCase(n, mem);
}
int stairCaseItr(int n){
    if(n == 0 || n == 1)
        return 1;
    if(n == 2)
        return 2;
    int * output = new int[n + 1];
    output[0] = 1;
    output[1] = 1;
    output[2] = 2;
    for(int i = 3; i <= n; i++){
        output[i] = output[i - 1] + output[i - 2] + output[i - 3];
    }
    int ans = output[n];
    delete [] output;
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<stairCaseItr(n)<<endl;
    return 0;
}