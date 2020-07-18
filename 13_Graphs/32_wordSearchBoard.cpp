#include <bits/stdc++.h>
using namespace std;

const int delta[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool existHelper(vector<string> &A, int x, int y, string B, int i) {
    if (i == B.size())
        return true;
    for (int j = 0; j < 4; j++) {
        int new_x = x + delta[j][0];
        int new_y = y + delta[j][1];
        if (new_x < 0 || new_x >= A.size() || new_y < 0 || new_y >= A[0].size() || 
            A[new_x][new_y] != B[i]) 
            continue;
        if (existHelper(A, new_x, new_y, B, i + 1)) {
            return true;
        }
    }
    return false;
    
}

int exist(vector<string> &A, string B) {
    vector<vector<bool>> visited(A.size(), vector<bool>(A[0].size(), false));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] == B[0] && existHelper(A, i, j, B, 1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n ; i++) {
        cin >> A[i];
    }
    string B;
    cin >> B;
    cout << exist(A, B) << endl;
    return 0;
}

/*

8 
FEDCBECD 
FABBGACG 
CDEDGAEC 
BFFEGGBA 
FCEEAFDA 
AGFADEAC 
ADGDCBAA 
EAABDDFF
BCDCB

*/