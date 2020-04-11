#include<iostream>
#include<set>
using namespace std;
class Compare{
    public:
    bool operator()(int a, int b){
        return a > b;
    }
};
int main(){
    set<int> first;
    int myInts[] = {10, 20, 30, 40, 50};
    set<int> second(begin(myInts), end(myInts));
    set<int, Compare> third(second.begin(), second.end());
    auto it = third.begin();
    while(it != third.end()){
        cout<<*it<<" ";
        it++;
    }
    cout<<"\n";
    for(auto x: third){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}