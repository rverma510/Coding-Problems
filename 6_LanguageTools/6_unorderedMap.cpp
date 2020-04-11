#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string, int> m;
    m["Mango"] = 100;
    m.insert(make_pair("Apple", 120));
    for(auto x: m){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    if(m.count("Apple") == 1)
        cout<<"Price of Apple : "<<m["Apple"]<<"\n";
    if(m.count("Guava") == 0)
        cout<<"Guava does not exist\n";
    m.erase("Mango");
    auto f = m.find("Mango");
    if(f != m.end())
        cout<<"Price of Mango : "<<m["Mango"]<<"\n";
    else 
        cout<<"Mango does not exist\n";
    return 0;
}