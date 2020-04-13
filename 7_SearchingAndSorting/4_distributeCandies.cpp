#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll arr[n];
        ll mx = INT_MIN;
        for(ll i = 0; i < n; i++){
            cin>>arr[i];
            if(mx < arr[i])
                mx = arr[i];
        }
        ll l = 0;
        ll r = mx;
        ll ans = 0;  
        while(l <= r){
            ll m = l + (r - l) / 2;
            ll temp = 0;
            for(ll i = 0; i < n; i++){
                temp += arr[i] / m;
            }
            if(temp >= k){
                ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}