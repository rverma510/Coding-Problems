#include<bits/stdc++.h>
using namespace std;
int main(){
    int *arr = new int[1001];
    for(int i=0;i<1001;i++)
        arr[i] = 0;
    int n;
    cin>>n;
    int mx = 0;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        arr[a]++;
        arr[b]++;
        if(arr[a] > mx)
            mx = arr[a];
        if(arr[b] > mx)
            mx = arr[b];
    }
    for(int i=0;i<1001;i++){
        if(arr[i] == mx)
            cout<<i<<" "; 
    }
    cout<<endl;
    return 0;
}