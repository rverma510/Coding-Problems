#include<bits/stdc++.h>
using namespace std;
void placeNQueens(int *queen, int n, int index){
    if(index == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(queen[i] == j)
                    cout<<1<<" ";
                else
                    cout<<0<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i = 0; i < n; i++){
        bool toAdd = true;
        for(int j = 0; j < index; j++){
            if(queen[j] == i || abs(queen[j] - i) == abs(index - j)){
                toAdd = false;
                break;
            }
        }
        if(toAdd){
            queen[index] = i;
            placeNQueens(queen, n, index + 1);
        }
    }
    return;
}
void placeNQueens(int n){
    int *queen = new int[n];
    placeNQueens(queen, n, 0);
}
int main(){
    int n;
    cin>>n;
    placeNQueens(n);
    return 0;
}