#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i = 0; i < n; i++)
        cin>>arr[i];
    ll w = -1;
    ll mn = 1e18;
    for(ll i = 0; i < n; i++){
        ll l = 0;
        ll r = 1e9;
        while(l <= r){
            ll mid = l + (r - l) / 2;
            if(i + mid * n >= arr[i]){
                if(mn > i + mid * n){
                    mn = i + mid * n;
                    w = i;
                }
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    }
    cout<<(w + 1)<<endl;
    return 0;
}