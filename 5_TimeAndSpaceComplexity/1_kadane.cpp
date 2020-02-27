#include<bits/stdc++.h>
using namespace std;

int kadane(int *arr, int n){
    int current_sum = 0;
    int best_sum = 0;
    for(int i=0;i<n;i++){
        current_sum += arr[i];
        if(current_sum < 0){
            current_sum = 0;
            continue;
        }
        if(best_sum < current_sum)
            best_sum = current_sum;
    }
    return best_sum;
}

int main(){
    int arr[] = {-5, 4, 9, -20, 3, 5, 8, -9};
    cout<<kadane(arr, 8);
    return 0;
}