#include<bits/stdc++.h>
using namespace std;

int lastIndexOfNumber(int *input, int size, int x){
    if(size == 0)
        return -1;
    if(input[size-1] == x)
        return size - 1;
    return lastIndexOfNumber(input, size-1, x);
}

int main(){
    int a[] = {2,52,6,37,2,732,3};
    cout<<lastIndexOfNumber(a, 7, 3)<<"\n";
    cout<<lastIndexOfNumber(a, 7, 5)<<"\n";
    return 0;
}