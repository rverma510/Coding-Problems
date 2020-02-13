#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    int count = 0;
    for(int i=0;i<n;i++){
        cin>>*(arr+i);
        if(*(arr + i) % 3 == 0)
            count++;
    }
    cout<<count<<endl;
    for(int i=0;i<n;i++){
        if(*(arr + i) % 3 == 0)
            cout<<*(arr+i)<<" ";
    }
    cout<<endl;
    return 0;
}