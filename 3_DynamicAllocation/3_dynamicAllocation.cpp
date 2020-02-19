#include<bits/stdc++.h>
using namespace std;
int main(){
    int *p = new int;
    *p = 10;
    cout<<*p<<endl;
    delete p;

    double *d = new double;
    char *c = new char;
    delete d;
    delete c;

    int *arr = new int[50];
    delete [] arr;

    int n;
    cin>>n;
    int *arr2 = new int[n];
    delete [] arr2;

   return 0;
}