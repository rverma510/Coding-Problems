#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a, int b){
    return a > b;
}
class Compare{
    public:
    bool operator()(int a, int b){
        return a > b;
    }

} obj;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a[] = {1, 3, 63, 1, 62, 524, 12};
    sort(begin(a), end(a), obj);
    for(auto i: a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}