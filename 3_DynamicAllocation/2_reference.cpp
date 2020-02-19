#include<bits/stdc++.h>
using namespace std;

void increment(int &n){
    n++;
}

// bad practice
int &f(int n){
    int a = n;
    return a;
}

// bad practice
int *f2(){
    int i = 10;
    return &i;
}

int main(){
    int i = 10;
    int &j = i;
    
    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;

    int k = 100;
    j = k;
    cout<<i<<" "<<j<<endl;

    increment(i);
    cout<<i<<endl;
    return 0;
}