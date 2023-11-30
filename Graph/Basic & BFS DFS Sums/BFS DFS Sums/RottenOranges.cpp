// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

// Example 1:

// Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
// Output: 1
// Explanation: The grid is-
// 0 1 2
// 0 1 2
// 2 1 1
// Oranges at positions (0,2), (1,2), (2,0)
// will rot oranges at (0,1), (1,1), (2,2) and 
// (2,1) in unit time.

#include <bits/stdc++.h>
using namespace std;


//------------METHOD 1---------------
bool isvalid(int x, int y, int row, int col){
    if(x<0 || y<0 || x>=row || y>=col) return false;
    return true;
}
int orangesRotting(vector<vector<int>>& grid) {
    // Code here
    int row = grid.size(), col = grid[0].size(), t=0, fresh =0;
    queue<pair<int, int>>q;
    for(int i =0; i<row; ++i){
        for(int j =0; j<col; ++j){
            if(grid[i][j]==2) q.push({i,j});
            else if(grid[i][j]==1) fresh++;
        }
    }
    if(fresh==0) return 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    while(!q.empty()){
        t++;
        int size = q.size();
        for(int i =0; i<size; ++i){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int j =0; j<4; ++j){
                int xdx = x + dx[j];
                int ydy = y + dy[j];
                if(isvalid(xdx, ydy, row, col) && grid[xdx][ydy]==1){
                    grid[xdx][ydy] =2;
                    fresh--;
                    q.push({xdx, ydy});
                }
            }
        }
        if(fresh==0) return t;
    }
    return -1;
}

//----------Method 2------------
int orangesRotting(vector<vector<int>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m];
    int freshCount = 0;
    int minTime = 0;
    queue<pair<pair<int,int>, int>> q;
    
    for (int i = 0; i< n; i++){
        for(int j = 0; j < m; j++) {
            if(grid[i][j]==2) {
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
            else {
                vis[i][j] = 0;
            }
            if(grid[i][j]==1) {
                freshCount++;
            }
        }
    }
    
    int row[] = {-1,0,1,0};
    int col [] = {0,1,0,-1};
    int count = 0;
        
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        minTime = max(minTime,t);
        for (int i = 0; i< 4; i++) {
            int nrow = r + row[i];
            int ncol = c + col[i];
            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1) {
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol] = 1;
                count++;
            }
        }
    }
    
    if(count != freshCount) {
        return -1;
    }
    
    return minTime;
}

