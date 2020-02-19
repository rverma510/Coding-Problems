#include<bits/stdc++.h>
using namespace std;
int main(){
    // constant integer
    const int i1 = 10;
    int const i2 = 30;
    // i = 12;

    // const int j;
    // j = 20;

    int j = 12;
    const int &k = j;
    j++;
    // k++;
    cout<<k<<endl;

    int const j2 = 12;
    int const &k2 = j2;
    // j2++;
    // k2++;

    int const j3 = 123;
    // int &k3 = j3;

    


    return 0;
}