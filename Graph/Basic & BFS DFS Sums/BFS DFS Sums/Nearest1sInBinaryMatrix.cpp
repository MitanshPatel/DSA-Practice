// Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell,
// and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.

// Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
// Output: {{0,1,0},{0,0,1},{0,1,2}}
// Explanation: The grid is-
// 1 0 1
// 1 1 0
// 1 0 0
// 0's at (0,1), (1,2), (2,1) and (2,2) are at a 
// distance of 1, 1, 1 and 2 from 1's at (0,0),
// (0,2), (2,0) and (1,1) respectively.
// ans:
// 0 1 0
// 0 0 1
// 0 1 2

#include <bits/stdc++.h>
using namespace std;
/*
Hello everyone this is a standerd bfs question as this question asks for
minimum distance from 1. To solve this question we need to follow thease steps.

    1.Take all 1's as the base level like a root of tree.
    2.Now make a answer matrix and initialize with -1.
    3.Find all 1 and push it to queue and update its distance to 0 in the answer matrix.
    4.Now traverse to all child of the 1's if the answer[i][j] of the child is -1 then update
    the answer by adding 1 to the distance of its parent.
    5.Finally return the answer matrix
    
    Similar question:
    Rotten oranges
    Knight Walk

*/
vector<vector<int>>nearest(vector<vector<int>>grid)
{
    // Code here
    int row = grid.size();
    int col = grid[0].size();
    
    queue<pair<int,int>> q;
    vector<vector<int>> ans(row,vector<int>(col,-1));
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==1) {
                q.push({i,j});
                ans[i][j]=0;
            }
        }
    }
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0 , 0};
    
    int level=0;
    
    while(!q.empty()){
        int size = q.size();
        level++;
        for(int i=0;i<size;i++) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int na = a+dx[k];
                int nb = b+dy[k];
                
                if(na<0||nb<0||na>=row||nb>=col||ans[na][nb]!=-1) continue;
                q.push({na,nb});
                ans[na][nb]=level;
            }
        }
    }
    return ans;
}