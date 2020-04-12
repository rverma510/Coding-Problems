#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int> s;
    unordered_map<int, int> m;
    int n, temp, start, end;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        s.insert(arr[i]);
        if(m.find(arr[i]) == m.end())
            m[arr[i]] = i;
    }
    vector<int> res;
    int mx = 0;
    for(int i = 0; i < n; i++){
        temp = start = end = arr[i];
        if(s.find(temp) != s.end()){
            s.erase(temp);
            while(true){
                temp--;
                if(s.find(temp) != s.end()){
                    start = temp;
                    s.erase(temp);
                }
                else
                    break;
            }
            temp = arr[i];
            while(true){
                temp++;
                if(s.find(temp) != s.end()){
                    end = temp;
                    s.erase(temp);
                }
                else
                    break;
            } 
        }
        if(mx < end - start + 1){
            res.clear();
            mx = end - start + 1;
            for(int j = start; j <= end; j++)
                res.push_back(j);
        }
        else if(mx != 0 && mx == end - start + 1 ){
            if(m[start] < m[res[0]]){
                res.clear();
                for(int j = start; j <= end; j++)
                    res.push_back(j);
            }
        }
    }
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<"\n";
    }
    return 0;
}