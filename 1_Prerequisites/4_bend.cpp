#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    int area1 = (x2 - x1) * (y2 - y1);
    int area2 = (x4 - x3) * (y4 - y3);
    int left = max(x1, x3);
    int right = min(x2, x4);
    int bottom = max(y1, y3);
    int top = min(y2, y4);
    int common = 0;
    if(left < right && bottom < top)
        common = (right - left) * (top - bottom);
    int res = area1 + area2 - common;
    cout<<res<<endl;
    return 0;
}