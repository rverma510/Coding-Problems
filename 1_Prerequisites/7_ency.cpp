#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        cout<<arr[temp-1]<<endl;
    }
    return 0;
}