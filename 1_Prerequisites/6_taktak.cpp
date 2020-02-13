#include<bits/stdc++.h>
using namespace std;

int func(int n){
    int i=0;
    while(true){
        int f = n * (1<<i);
        if(f % 11 == 1)
            break;
        i++;
    }
    return i;

}

int main(){
    int n;
    cin>>n;
    int res = func(n);
    cout<<res<<" "<<(n*(1<<res));
    return 0;
}