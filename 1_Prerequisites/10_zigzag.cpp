#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i%2==0)
                cout<<arr[j][i]<<" ";
            else
                cout<<arr[n-j-1][i]<<" ";
        }
    }
    return 0;
}