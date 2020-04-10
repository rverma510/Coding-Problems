#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    ll *p = new ll[n];
    ll temp;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    temp = 1;
    for(int i=0;i<n;i++){
        p[i] = temp;
        temp *= arr[i];
    }
    temp = 1;
    for(int i=n-1;i>=0;i--){
        p[i] *= temp;
        temp *= arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    return 0;
}