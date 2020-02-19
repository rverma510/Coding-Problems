#include<bits/stdc++.h>
using namespace std;
int main(){
    int const i = 10;
    // int *p = &i;
    int const *p = &i;
    // (*p)++;
    int j = 12;
    int const *p2 = &j;
    cout<<*p2<<endl;
    j++;
    cout<<*p2<<endl;
    return 0;

    int k = 10;
    int l = 20;
    int const *p3 = &k;
    p3 = &l;

    int * const p4 = &k;
    (*p4)++;
    //p4 = &l;

    int const * const p5 = &k;
    // p5 = &l;
    // (*p5)++;
}