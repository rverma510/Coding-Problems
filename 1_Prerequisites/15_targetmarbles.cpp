#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum = 0;
    int start, end;
    start = end = -1;
    for(int i=0;i<n;i++)
        if(arr[i] <= m){
            sum = arr[i];
            start = i;
            end = i;
            break;
        }
    for(int i=start+1;i<n;i++){
        if(sum == m)
            break;
        sum += arr[i];
        end = i;
        while(sum > m && start <= end){
            sum -= arr[start];
            start++;
        }
    }
    if(sum == m){
        cout<<"true"<<endl;
        for(int i=start;i<=end;i++)
            cout<<arr[i]<<" ";
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}