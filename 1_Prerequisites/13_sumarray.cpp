#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            if(i==0 || i==n-1 || j==0|| j==n-1|| i==j || i+j == n-1)
                sum += temp;
        }
    }
    cout<<sum<<endl;
    return 0;
}