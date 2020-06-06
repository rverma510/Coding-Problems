#include<bits/stdc++.h>
using namespace std;
int depth(char *s, int &idx) {
    if (s[idx] == '\0')
        return INT_MIN;
    if (s[idx] == 'l') {
        idx++;
        return 0;
    }
    idx++;
    int ans1 = depth(s, idx);
    int ans2 = depth(s, idx);
    return 1 + max(ans1, ans2);    
}
int main() {
    char *s = new char[10000];
    cin>>s;
    int idx = 0;
    cout<<depth(s, idx)<<endl;
    return 0;
}