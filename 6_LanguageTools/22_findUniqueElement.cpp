#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> m;
    int n, temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        m[temp]++;
    }
    for(auto x: m){
        if(x.second == 1){
            cout<<x.first<<endl;
            break;
        }
            
    }
    return 0;
}