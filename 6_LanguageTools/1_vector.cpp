#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> V;
    V.reserve(1000);
    cout<<V.size()<<"\n";
    cout<<V.capacity()<<"\n";
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        V.push_back(temp);
    }
    cout<<V.size()<<"\n";
    V.pop_back();
    cout<<V.size()<<"\n";
    sort(V.begin(), V.end());
    for(auto it = V.begin(); it != V.end(); it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    V.clear();
    cout<<V.size()<<"\n";
    return 0;
}