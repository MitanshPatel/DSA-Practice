// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Input:
// grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
// Output:
// 2
// Expanation:
// The grid is-
// 0 1 1 1 0 0 0
// 0 0 1 1 0 1 0 
// There are two islands :- one is colored in blue 
// and other in orange.

#include <bits/stdc++.h>
using namespace std;

//-------DFS----------
void dfs(vector<vector<char>>&grid , int i ,int j){
    int n = grid.size();
    int m = grid[0].size();
    if(i<0|| j<0|| i>=n|| j>=m) return;
    if(grid[i][j]!='1') return;
    grid[i][j]='2';
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j-1);
    dfs(grid,i,j+1);
    dfs(grid,i+1,j+1);
    dfs(grid,i-1,j+1);
    dfs(grid,i+1,j-1);
    dfs(grid,i-1,j-1);
}
int numIslands(vector<vector<char>>& grid) {
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(grid[i][j]=='1') {
                dfs(grid,i,j);
                count++;
            }
        }
    }
    return count;
}

//----------BFS-------
void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        // traverse in neighbour and mark them if its a land.
        for(int delrow = -1; delrow<=1; delrow++){
            for(int delcol = -1; delcol<=1; delcol++){
                int nrow = row+delrow;
                int ncol = col+delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]== '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}
// Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) {
    // Code here, 3 july 2023
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int cnt = 0;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(grid[row][col]== '1' && !vis[row][col]){
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt++;
}