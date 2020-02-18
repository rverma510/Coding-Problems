#include<bits/stdc++.h>
using namespace std;
int main(){
    int i;
    cout<<i<<endl;

    i++;
    cout<<i<<endl;

    int *p;
    // Make sure to point it to 0 
    // int *p = 0;
    cout<<p<<endl;

    cout<<*p<<endl; // This is dangerous.

    return 0;
}