#include<bits/stdc++.h>
using namespace std;

int countNumberOfDigits(int n){
    if(n == 0)
        return 0;
    return 1 + countNumberOfDigits(n/10);
}

int main(){
    int n;
    cin>>n;
    int res = countNumberOfDigits(n);
    cout<<res<<"\n";
    return 0;
}