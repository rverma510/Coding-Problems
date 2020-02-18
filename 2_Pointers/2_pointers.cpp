#include<bits/stdc++.h>
using namespace std;
int main(){
    int i = 10;
    int *p = &i;
 
    cout<<sizeof(i)<<endl;
    cout<<sizeof(p)<<endl;

    cout<<i<<endl;
    cout<<*p<<endl;

    i++;

    cout<<i<<endl;
    cout<<*p<<endl;

    int a = i;
    a++;
    cout<<i<<endl;
    cout<<a<<endl;
    cout<<*p<<endl;

    (*p)++;
    cout<<i<<endl;
    cout<<*p<<endl;
    
    return 0;
}