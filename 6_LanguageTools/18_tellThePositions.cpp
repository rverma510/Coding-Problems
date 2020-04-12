 #include<bits/stdc++.h>
 using namespace std;
 bool compare(pair<int, int> a, pair<int, int> b){
     if(a.first > b.first)
        return true;
    else if(a.first < b.first)
        return false;
    else
        return a.second < b.second;
 }
 int main(){
    int n;
    cin>>n;
    vector<string> s;
    vector<pair<int, int>> res;
    for(int i = 0; i < n; i++){
        string temp;
        int a, b, c;
        cin>>temp>>a>>b>>c;
        a = a + b + c;
        s.push_back(temp);
        res.push_back({a, i});
    }
    sort(res.begin(), res.end(), compare);
    for(int i = 0; i < n; i++){
        cout<<(i + 1)<<" "<<s[res[i].second]<<"\n";
    }
    return 0;
 }