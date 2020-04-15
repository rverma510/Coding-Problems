#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j, k;
    int arr1[n1];
    int arr2[n2];
    for(i = 0; i < n1; i++)
        arr1[i] = arr[i + l];
    for(j = 0; j < n2; j++)
        arr2[j] = arr[j + m + 1];
    i = j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr[k++] = arr1[i++]; 
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
}
void merge_sort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l , m, r);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    merge_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}