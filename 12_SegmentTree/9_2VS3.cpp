/*
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.
It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to 
solve this problem and then you get the right to choose the best number in the globe.

Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.

Output:
For each query of Type 0 print the value modulo 3.

Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N

Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3

Sample Output
2
1
2
1
*/
#include <bits/stdc++.h>
using namespace std; 
int p[100006], arr[100006], tree[300000]; 
void fastpow() { 
    p[0]=1; 
    for(int i=1;i<100006;i++) 
        p[i]=(p[i-1]*2)%3; 
} 
void build(int i, int st, int en) { 
    if(st==en) 
        tree[i]=arr[st]; 
    else { 
        int mid=(st+en)/2; 
        build(2*i,st,mid); 
        build(2*i+1,mid+1,en); 
        tree[i]=(tree[2*i]*p[en-mid]+tree[2*i+1])%3; 
    } 
} 
int query(int i, int st, int en, int l, int r) { 
    if(r<st or l>en ) 
        return 0; 
    if(l<=st and r>=en) 
        return (tree[i]*p[r-en])%3; 
    int mid=(st+en)/2; 
    int p1=query(2*i, st, mid, l, r); 
    int p2=query(2*i+1,mid+1,en,l,r); 
        return (p1+p2)%3; 
} 
void update(int i, int st, int en, int idx) { 
    if(st==en) { 
        tree[i]=1; 
        arr[idx]=1; 
    } 
    else { 
        int mid=(st+en)/2; 
        if(st<=idx and mid>=idx) { 
            update(2*i, st, mid, idx); 
        } 
        else { 
            update(2*i+1, mid+1, en, idx); 
        } 
        tree[i]=(tree[2*i]*p[en-mid]%3)+tree[2*i+1]%3; 
    } 
} 
int main() { 
    int n; 
    cin>>n; 
    string s; 
    cin>>s; 
    fastpow(); 
    for(int i=0;i<n;i++) { 
        arr[i+1]=s[i]-48; 
    } 
    build(1, 1, n); 
    int q; 
    cin>>q; 
    while(q--) { 
        int t; 
        cin>>t; 
        if(t==0) { 
            int l,r; 
            cin>>l>>r; 
            cout<<query(1,1,n,l+1,r+1)<<"\n"; 
        } 
        else { 
            int x; 
            cin>>x; 
            if(s[x]=='0') { 
                s[x]='1'; 
                arr[x+1]=1; 
                update(1,1,n,x+1); 
            } 
        } 
    } 
}