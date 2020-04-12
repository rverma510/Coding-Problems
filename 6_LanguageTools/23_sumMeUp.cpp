#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll sumOfDigits(ll val){
    ll sum = 0;
    while(val){
        sum += val % 10;
        val /= 10;
    }
    return sum;
}
int main() {
    ll t, val;
    cin>>t;
    while(t--){
        cin>>val;
        cout<<sumOfDigits(val)<<endl;
    }
    return 0;
}