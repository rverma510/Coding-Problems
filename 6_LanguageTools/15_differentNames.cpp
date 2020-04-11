#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string, int> m;
    int flag = 0;
    string s;
    getline(cin, s);
    string temp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' || i == s.size() - 1){
            if(i == s.size() - 1)
                temp += s[i];
            m[temp]++;
            if(m[temp] > 1)
                flag = 1;
            temp = "";
            continue;
        }
        temp += s[i];
    }
    if(flag){
        for(auto x: m){
            if(x.second > 1)
                cout<<x.first<<" "<<x.second<<endl;
        }
    }
    else
        cout<<-1<<endl;
    return 0;
}