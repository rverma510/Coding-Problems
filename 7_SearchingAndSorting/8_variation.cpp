#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr, arr + n);
    int pr = 0;
    for(int i = 0; i < n - 1; i++){
        pr += (arr + n) - lower_bound(arr + i + 1, arr + n, abs(arr[i] + k));
    }
    cout<<pr<<endl;

    return 0;
}