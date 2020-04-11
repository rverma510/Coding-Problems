#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(int i, int j){
    return i < j;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int arr[] = {10, 10, 20, 20, 20, 30};
    vector<int> V(arr, arr + 6);
    bool present = binary_search(V.begin(), V.end(), 10, compare);
    cout<<present<<"\n";
    vector<int>::iterator low, up;
    low = lower_bound(V.begin(), V.end(), 20);
    up = upper_bound(V.begin(), V.end(), 20);
    cout<<"Lower bound of 20 : "<<low - V.begin()<<"\n";
    cout<<"Upper bound of 20 : "<<up - V.begin()<<"\n";
    return 0;
}