/*
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can go to usually 
and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, 
calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7

Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.

Output:
For each test case, output the number of photographs taken by photographer.

Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M

SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4

SAMPLE OUTPUT
4
2
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int arr[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void getCountOfConnectedHorses(int **edges, int n, int m, int i, int j, bool **visited, ll &tmp) {
    tmp++;
    visited[i][j] = true;
    for (int k = 0; k < 8; k++) {
        int newI = i + arr[k][0];
        int newJ = j + arr[k][1];
        if (newI < 0 || newI >= n || newJ < 0 || newJ >= m) 
            continue;
    	if(!visited[newI][newJ])
            getCountOfConnectedHorses(edges, n, m, newI, newJ, visited, tmp);
    }
}

ll getResult(int **edges, int n, int m) {
    bool **visited = new bool*[n];
    for (int i = 0; i < n; i++) {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++) {
            if (edges[i][j] == 0)
                visited[i][j] = true;
        	else
                visited[i][j] = false;
        }
    }
    ll res = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                ll tmp = 0;
                getCountOfConnectedHorses(edges, n, m, i, j, visited, tmp);
            	while (tmp > 0) {
                    res *= tmp % mod;
                    res %= mod;
                    tmp--;
                }
            }
        }
    }
    return res % mod;
} 

int main() {
	int t;
    cin>>t;
    while (t--) {
        int n, m, q, x, y;
        cin>>n>>m>>q;
        int **edges = new int*[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new int[m];
            for (int j = 0; j < m; j++) {
                edges[i][j] = 0;
            }
        }
        for (int i = 0; i < q; i++) {
            cin>>x>>y;
            edges[x - 1][y - 1] = 1;
        }
        cout<<getResult(edges, n, m)<<endl;
    }
	return 0;
}
