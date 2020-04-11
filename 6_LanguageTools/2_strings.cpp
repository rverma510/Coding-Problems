#include<iostream>
#include<string>
using namespace std;
int main(){
    string s0("Initial String");
    cout<<s0<<endl;
    string s1;
    cout<<s1<<endl;
    string s2(s0);
    cout<<s2<<endl;
    string s3(s0, 8, 3);
    cout<<s3<<endl;
    string s4("A character sequence", 12);
    cout<<s4<<endl;
    string s5a(10, 'x');
    cout<<s5a<<endl;
    string s5b(10, 42);
    cout<<s5b<<endl;
    for(auto it = s0.begin(); it != s0.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Size of string s0 : "<<s0.size()<<"\n";
    string s8;
    getline(cin, s8);
    cout<<s8<<endl;
    string s9 = s8.substr(3, 2);
    cout<<s9<<endl;
    size_t found = s0.find("in");
    if(found != string::npos)
        cout<<"in found at : "<<found<<endl;
    return 0;
}