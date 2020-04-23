#include<bits/stdc++.h>
using namespace std;
bool checkPowerOfTwo(int n){
    int sum = 0;
    for(int i = 0; i < 32; i++){
        if(n & (1 << i))
            sum++;
    }
    if(sum <= 1)
        return true;
    return false;
}
int main(){
    int n;
    cin>>n;
    cout<<checkPowerOfTwo(n);
    return 0;
}