#include<bits/stdc++.h>
using namespace std;
#define n 9
typedef long long int ll;
bool findEmptyLocation(int **arr, int &row, int &col){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isPossible(int **arr, int row, int col, int i){
    for(int j = 0; j < n; j++){
        if(arr[row][j] == i || arr[j][col] == i){
            return false;
        }
    }
    for(int  j = 3 * (row / 3); j < 3 * (row / 3) + 3; j++){
        for(int  k = 3 * (col / 3); k < 3 * (col / 3) + 3; k++){
            if(arr[j][k] == i)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int **arr){
    int row, col;
    if(!findEmptyLocation(arr, row, col)){
        return true;
    }
    for(int i = 1; i <= 9; i++){
        if(isPossible(arr, row, col, i)){
            arr[row][col] = i;
            if(solveSudoku(arr)){
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int **arr = new int*[n];
    ll num, ten = 10;
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
        cin>>num;
        for(int j = n - 1; j >= 0; j--){
            arr[i][j] = num % ten;
            num /= ten;
        }
    }
    solveSudoku(arr);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}