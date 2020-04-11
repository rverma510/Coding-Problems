#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n, m;
    cin>>n>>m;
    ll arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr, arr + n);
    queue<ll> q1, q2;
    for(int i = n - 1; i >= 0; i--)
        q1.push(arr[i]);
    ll count = 1, temp;
    while(m--){
        ll ans;
        cin>>temp;
        for(; count <= temp; count++){
            if(q2.empty()|| q1.front() >= q2.front())
                ans = q1.front(), q1.pop();
            else
                ans = q2.front(), q2.pop();
            q2.push(ans >> 1);
        }
        cout<<ans<<endl;
    }
    return 0;
}