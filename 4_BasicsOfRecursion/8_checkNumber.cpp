#include<bits/stdc++.h>
using namespace std;

bool checkNumber(int *input, int size, int x){
    if(size == 0)
        return false;
    if(input[0] == x)
        return true;
    return checkNumber(input+1, size-1, x);
}

int main(){
    int a[] = {3,52,6,37,2,732,3};
    cout<<checkNumber(a, 7, 52)<<"\n";
    cout<<checkNumber(a, 7, 5)<<"\n";
    return 0;
}