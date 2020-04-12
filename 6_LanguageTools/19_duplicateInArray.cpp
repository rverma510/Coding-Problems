#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n, temp, sum = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>temp;
        sum += temp;
    }
    cout << (sum - ((n - 2) * (n - 1)) / 2)<<endl;
    return 0;
}