#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n], dep[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    for(int i = 0; i < n; i++)
        cin>>dep[i];
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 0, j = 0;
    int curr = 0, mx = INT_MIN;
    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            curr++;
            i++;
        }
        else{
            j++;
            curr--;
        }
        mx = max(mx, curr);
    }
    curr += n - i;
    mx = max(mx, curr);
    cout<<mx<<endl;
    return 0;
}