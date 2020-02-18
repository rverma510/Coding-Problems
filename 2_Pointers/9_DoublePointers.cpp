#include<bits/stdc++.h>
using namespace std;

void increment1(int **p){ // no changes here.
    p++;
}

void increment2(int **p){ // will make changes to the pointer.
    (*p)++;
}

void increment(int **p){ // will make change to the integer value.
    (**p)++;
}

int main(){
    int i = 10;
    int *p = &i;
    int **p2 = &p;
    cout<<p2<<endl;
    cout<<&p<<endl;
    cout<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl;
    cout<<&i<<endl;
    cout<<endl;
    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;
    return 0;
}