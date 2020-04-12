#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, d;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>d;
    d = d % n;
    queue<int> q;
    for(int i = 0; i < d; i++){
        q.push(arr[i]);
    }
    for(int i = 0; i < n - d; i++){
        arr[i] = arr[i + d];
    }
    for(int i = n - d; i < n; i++){
        arr[i] = q.front();
        q.pop();
    }
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    return 0;
}