#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll merge(int *arr, int l, int m, int r){
    ll n1 = m - l + 1;
    ll n2 = r - m;
    ll i, j, k;
    ll arr1[n1];
    ll arr2[n2];
    for(i = 0; i < n1; i++)
        arr1[i] = arr[i + l];
    for(j = 0; j < n2; j++)
        arr2[j] = arr[j + m + 1];
    i = j = 0;
    k = l;
    ll sum = 0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            sum += arr1[i] * (n2 - j);
            arr[k++] = arr[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
    }
    while(i < n1){
        arr[k++] = arr1[i++];
    }
    while(j < n2){
        arr[k++] = arr2[j++];
    }    
    return sum;
}
ll merge_sort(int *arr, int l, int r){
    if(l >= r)
        return 0;
    int m = l + (r - l) / 2;
    ll ans1 = merge_sort(arr, l, m);
    ll ans2 = merge_sort(arr, m + 1, r);
    return ans1 + ans2 + merge(arr, l, m, r);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        cout<<merge_sort(arr, 0, n - 1)<<endl;
    }
    
    return 0;
}