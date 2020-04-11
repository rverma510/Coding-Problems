#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string> s;
    s.push("raghav");
    s.push("rv");
    s.push("rverma510");
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\b";
    return 0;
}