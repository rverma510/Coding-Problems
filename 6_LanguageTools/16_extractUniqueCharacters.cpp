#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<char> s;
    string str, res = "";
    cin>>str;
    for(int i = 0; i < str.size(); i++){
        if(s.find(str[i]) != s.end())
            continue;
        res += str[i];
        s.insert(str[i]);
    }
    cout<<res<<endl;
    return 0;
}