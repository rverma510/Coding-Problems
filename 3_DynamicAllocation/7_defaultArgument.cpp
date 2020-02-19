#include<bits/stdc++.h>
using namespace std;

int sum(int a[], int size, int si=0){
    int ans = 0;
    for(int i=si;i<size;i++)
        ans += a[i];
    return 0;
}

int main(){
    int a[20];
    // input code for a
    cout<<sum(a, 20, 0)<<endl;
    return 0;
}