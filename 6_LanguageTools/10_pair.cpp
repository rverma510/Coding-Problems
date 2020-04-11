#include<bits/stdc++.h>
#include<utility>
#include<vector>
using namespace std;
int main(){
    pair<int, char> p;
    p = make_pair(2, 'b');
    cout<<p.first<<" "<<p.second<<"\n";
    pair<int, char> p2(1, 'a');
    cout<<p2.first<<" "<<p2.second<<"\n";
    
    return 0;
}