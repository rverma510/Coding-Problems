#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int arr1[n1];
    int arr2[n2];
    for(int i = 0; i < n1; i++)
        arr1[i] = arr[i + l];
    for(int j = 0; j < n2; j++)
        arr2[j] = arr[j + mid + 1];
    int k = l, i = 0, j = 0;
    int count = 0;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            count += n1 - i;
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
    return count;
}

int merge_sort(int arr[], int l, int r){
    if( l >= r)
        return 0;
    int mid = l + (r - l) / 2;
    int ans1 = merge_sort(arr, l, mid);
    int ans2 = merge_sort(arr, mid + 1, r);
    return ans1 + ans2 + merge(arr, l, mid, r);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<merge_sort(arr, 0, n - 1)<<endl;
    return 0;
}