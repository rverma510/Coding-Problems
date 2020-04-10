#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll maxProdSubArray(int *arr, int n){
    ll maxEndingHere = 1, minEndingHere = 1;
    ll maxProd = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            maxEndingHere *= arr[i];
            minEndingHere = min((ll)1, minEndingHere * arr[i]);
        }
        else if(arr[i] < 0){
            ll temp = maxEndingHere;
            maxEndingHere = max((ll)1, minEndingHere * arr[i]);
            minEndingHere = temp * arr[i];
        }
        else{
            minEndingHere = maxEndingHere = 1;
        }
        if(maxProd < maxEndingHere)
            maxProd = maxEndingHere;
    }
    return maxProd;
} 

int main(){
    int n; 
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxProdSubArray(arr, n)<<"\n";
    return 0;
}