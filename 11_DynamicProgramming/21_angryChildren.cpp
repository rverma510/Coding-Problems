#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int n, k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr, arr + n);
    ll ans = INT_MAX;
    ll target = 0;
    ll sum = 0;
    for(int i = 1; i < k; i++){
        sum += arr[i - 1];
        target += i * arr[i] - sum;
    }
    sum += arr[k - 1];
    if(ans > target)
        ans = target;
    for(int i = k; i < n; i++){
        sum -= arr[i - k];
        target = target - 2 * sum + (k - 1) * (arr[i - k] + arr[i]);
        sum += arr[k];
        if(ans > target)
            ans = target;
    }
    cout<<ans<<endl;
    return 0;
}