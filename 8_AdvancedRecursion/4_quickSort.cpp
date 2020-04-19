#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int s, int e){
    int key = arr[e];
    int i = s - 1;
    for(int j = s; j < e; j++){
        if(arr[j] <= key){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[e]);
    return i;
}
void quickSort(int arr[], int s, int e){
    if(s < e){
        int p = partition(arr, s, e);
        quickSort(arr, s , p - 1);
        quickSort(arr, p + 1, e);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}   