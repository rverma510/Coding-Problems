#include<bits/stdc++.h>
using namespace std;

int firstIndexOfNumber(int *input, int i, int size, int x){
    if(size == i)
        return -1;  
    if(input[i] == x)
        return i;
    return firstIndexOfNumber(input, i+1, size, x);
    
}

int main(){
    int a[] = {2,52,6,37,2,732,3};
    cout<<firstIndexOfNumber(a, 0, 7, 3)<<"\n";
    cout<<firstIndexOfNumber(a, 0, 7, 5)<<"\n";
    return 0;
}