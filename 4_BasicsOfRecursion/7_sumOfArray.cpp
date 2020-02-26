#include<bits/stdc++.h>
using namespace std;

int sum(int *input, int n){
    if(n == 0)
        return 0;
    return input[0] + sum(input+1, n-1);
}

int main(){
    int a[] = {1,2,3,4,5};
    cout<<sum(a, 5)<<"\n";
    return 0;
}