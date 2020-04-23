#include<bits/stdc++.h>
using namespace std;
void checkOddOrEven(int n){
    if(n & 1)
        cout<<"Odd\n";
    else
        cout<<"Even\n";
}
int main(){
    int n;
    cin>>n;
    checkOddOrEven(n);
    return 0;
}