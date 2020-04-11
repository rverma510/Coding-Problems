#include<iostream>
#include<queue>
using namespace std;
class Compare{
    public:
    bool operator()(int a, int b){
        return a > b; // for min heap
    }
};
int main(){
priority_queue<int, vector<int>, Compare> pq;
priority_queue<int, vector<int>, less<int>> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;
pq.push(1);
pq.push(5);
pq.push(3);
pq.push(2);
pq.push(6);
pq.push(2);
while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
}
cout<<"\n";
return 0;
}
