#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int minIndex = 0;
    int maxProf = 0;
    for(int i=1;i<n;i++){
        if(arr[minIndex] > arr[i])
            minIndex = i;
        if(maxProf < arr[i] - arr[minIndex])
            maxProf = arr[i] - arr[minIndex];
    }
    cout<<maxProf<<endl;
    return 0;
}