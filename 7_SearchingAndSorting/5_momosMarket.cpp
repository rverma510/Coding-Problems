#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){ 
    ll n, q, x;
    cin>>n;
    ll arr[n];
    for(ll i = 0; i < n; i++){
        ll temp;
        cin>>temp;
        if(i == 0){
            arr[i] = temp;
            continue;
        }
        arr[i] = arr[i - 1] + temp;
    }
    cin>>q;
    for(ll i = 0; i < q; i++){
        cin>>x;
        ll l = 0, r = n - 1;
        ll ans = -1;
        while(l <= r){
            ll m = l + (r - l) / 2;
            if(arr[m] <= x){
                ans = m ;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        if(ans == -1)
            cout<<(ans + 1)<<" "<<x<<endl;
    	else
        	cout<<(ans + 1)<<" "<<(x - arr[ans])<<endl;
    }
    return 0;
}