#include<bits/stdc++.h>
using namespace std;
int main(){

    int a[10];
    cout<<a<<endl;
    cout<<&a[0]<<endl;

    a[0] = 5;
    cout<<*a<<endl;

    a[1] = 10;
    cout<<a+1<<endl;
    cout<<*(a+1)<<endl;
    cout<<1[a]<<endl;

    cout<<sizeof(a)<<endl;
    cout<<sizeof(&a[0])<<endl;
    cout<<&a<<endl;

    int *p = &a[0];
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<&a<<endl;
    cout<<&p<<endl;

    p = p + 1;
    // a = a + 1; Cannot do this

    return 0;
}