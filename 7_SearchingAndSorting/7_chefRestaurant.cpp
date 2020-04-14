#include<bits/stdc++.h>
using namespace std;
struct Interval{
    int start;
    int end;
};
bool compare(Interval a, Interval b){
    return a.start < b.start;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<Interval> v;
        for(int i = 0; i < n; i++){
            Interval temp;
            cin>>temp.start>>temp.end;
            v.push_back(temp);
        }
        sort(v.begin(), v.end(), compare);
        for(int i = 0; i < m; i++){
            int temp;
            cin>>temp;
            if(temp < v[0].start){
                cout<<(v[0].start - temp)<<endl;
                continue;
            }
            if(temp >= v[n - 1].end){
                cout<<(-1)<<endl;
                continue;
            }
            int l = 0, r = n - 1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(v[mid].start <= temp && temp < v[mid].end){
                    cout<<0<<endl;
                    break;
                }
                else if(v[mid].end <= temp && temp < v[mid + 1].start){
                    cout<<(v[mid + 1].start - temp)<<endl;
                    break;
                }
                if(temp >= v[mid + 1].start)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
    }
    return 0;
}