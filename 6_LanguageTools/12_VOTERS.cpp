#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    map<ll, ll> m;
    set<ll> s;
    ll n1, n2, n3;
    cin>>n1>>n2>>n3;
    for(int i = 0; i < n1 + n2 + n3; i++){
        ll temp;
        cin>>temp;
        m[temp]++;
        if(m[temp] >= 2)
            s.insert(temp);
    }
    cout<<s.size()<<endl;
    for(auto x: s){
        cout<<x<<endl;
    }
    return 0;
}