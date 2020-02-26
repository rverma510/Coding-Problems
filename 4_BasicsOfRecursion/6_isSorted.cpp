#include<bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int size){
    if(size == 0 || size == 1)
        return true;
    if(a[0] > a[1])
        return false;
    return isSorted(a+1, size-1);
}

int main(){
    int a[] = {1,2,3,4,5};
    int b[] = {5,4,3,2,1};
    cout<<isSorted(a, 5)<<"\n";
    cout<<isSorted(b, 5)<<"\n";
    return 0;
}