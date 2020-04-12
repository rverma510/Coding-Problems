#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> pos, neg;
    int n, temp;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>temp;
        if(temp >= 0)
            pos[temp]++;
        else
            neg[temp]++;
    }
    for(auto x: neg){
        if(pos.find(-x.first) != pos.end()){
            int count = neg[x.first] * pos[-x.first];
            for(int i = 0; i < count; i++)
                cout<<x.first<<" "<<-x.first<<endl;
        }
    }
    return 0;
}