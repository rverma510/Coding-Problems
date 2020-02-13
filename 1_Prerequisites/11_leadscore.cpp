#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int p1[n+1], p2[n+1];
    p1[0] = 0;
    p2[0] = 0;
    int lead_player = -1;
    int lead_score = -1;
    for(int i=1;i<=n;i++){
        cin>>p1[i]>>p2[i];
        p1[i] += p2[i-1];
        p2[i] += p2[i-1];
        if(p1[i] > p2[i] && lead_score < p1[i] - p2[i]){
            lead_score = p1[i] - p2[i];
            lead_player = 1;
        }
        else if(p2[i] > p1[i] && lead_score < p2[i] - p1[i]){
            lead_score = p2[i] - p1[i];
            lead_player = 2;
        }
    }
    cout<<lead_player<<" "<<lead_score<<endl;
    return 0;
}