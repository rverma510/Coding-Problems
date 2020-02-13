#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int even, odd;
    even = odd = 0;
    for(int i=0;i<n;i++){
        if(i%2 == 0 && arr[i] % 2 ==0)
            even += arr[i];
        else if(i%2 == 1 && arr[i] % 2 == 1)
            odd += arr[i];
    }
    cout<<even<<" "<<odd<<endl;
    return 0;
}