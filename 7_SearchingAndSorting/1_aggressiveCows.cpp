#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        sort(arr, arr + n);
        int l = arr[0];
        int r = arr[n - 1] - arr[0];
        int mn = 0;
        while(l <= r){
            int mid = l + (r -l) / 2;
            int curr = arr[0];
            int count = 1;
            for(int i = 1; i < n; i++){
                if(arr[i] - curr >= mid){
                    curr = arr[i];
                    count++;
                }
            }
            if(count >= c){
                mn = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}