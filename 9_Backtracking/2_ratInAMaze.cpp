#include<bits/stdc++.h>
using namespace std;
void ratInAMaze(int maze[][20], int n, int i, int j){
    if(i == n - 1 && j == n - 1){
        if(maze[i][j] == 1){
            maze[i][j] = 2;
        	for(int a = 0; a < n; a++){
                for(int b = 0; b < n; b++){
                    if(maze[a][b] == 2)
                        cout<<1<<" ";
                    else
                        cout<<0<<" ";
                }
            }
            maze[i][j] = 1;
        	cout<<endl;
        }
        return;
    }
    if(i < 0 || i >= n || j < 0 || j >= n)
        return;
	if(maze[i][j] == 1){
        maze[i][j] = 2;
        ratInAMaze(maze, n, i + 1, j);
        ratInAMaze(maze, n, i, j + 1);
        ratInAMaze(maze, n, i - 1, j);
        ratInAMaze(maze, n, i, j - 1);
        maze[i][j] = 1;
    }
    
    return;
}
void ratInAMaze(int maze[][20], int n){
 	ratInAMaze(maze, n, 0, 0);
}
int main(){
  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}