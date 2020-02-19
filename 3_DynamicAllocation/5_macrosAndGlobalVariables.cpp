#include<bits/stdc++.h>
using namespace std;
#define PI 3.14

// It is best not to use global variable
int i;

void g(){
    i++;
    cout<<i<<endl;
}

void f(){
    cout<<i<<endl;
    i++;
}

int main(){
    int r = 10;
    cout<<PI*r*r<<endl;

    i = 10;
    f();
    g();
    return 0;
}