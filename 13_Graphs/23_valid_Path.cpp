#include<bits/stdc++.h>
using namespace std;
int delta[8][2] = {{-1, -1}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, -1}};
bool checkPath(bool **arr, int x, int y, int M, int N) {
    if (x == M && y == N)
        return true;
    arr[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int new_x = x + delta[i][0];
        int new_y = y + delta[i][1];
        if (new_x < 0 || new_x > M || new_y < 0 || new_y > N)
            continue;
        
        if (!arr[new_x][new_y] && checkPath(arr, new_x, new_y, M, N))
            return true; 
            
    }
    return false;
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    bool **arr = new bool*[A + 1];
    for (int i = 0; i <= A; i++) {
        arr[i] = new bool[B + 1];
        for (int j = 0; j <= B; j++) {
            arr[i][j] = false;
        }
    }
    for (int i = 0; i <= A; i++){
        for (int j = 0; j <= B; j++) {
            for (int k = 0; k < C; k++) {
                if (pow(E[k]-i, 2) + pow(F[k]-j, 2) <= pow(D, 2)) {
                    arr[i][j] = true;
                    break;
                }
            }
        }
    }

    if (arr[0][0] || arr[A][B])
        return "NO";
    
    if (checkPath(arr, 0, 0, A, B))
        return "YES";
    else
        return "NO";
}
int main() {
    int A, B, C, D;
    vector<int> E, F;
    cin>>A>>B>>C>>D;
    for (int i = 0; i < C; i++) {
        int temp; cin>>temp;
        E.push_back(temp);
    }
    for (int i = 0; i < C; i++) {
        int temp; cin>>temp;
        F.push_back(temp);
    }
    string ans = solve(A, B, C, D, E, F);
    cout << ans <<endl;
    return 0;
}

/*

41
 67
5
0
17 16 12 0 40
52 61 61 25 31

*/