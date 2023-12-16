// You are given an n x n integer matrix grid where each value grid[i][j] represents the height of the cell (i, j).
// You can travel from a cell to another 4-directionally adjacent cell if and only the height of both the cells are at most T.
// You can travel infinite distances in zero time but you must stay within the boundaries of the grid during your travel.
// You are currently at cell (0, 0) and the value of T is 0 and you wish to go to cell (n-1,m-1).
// Find the minimum time it will take to reach the cell (n, m) if the value of T increase by 1 every second.

// Example 1:

// Input:
// 2
// 0 2
// 1 3

// Output:
// 3

// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
// You cannot reach point (1, 1) until time 3.
// When time T is 3, we can swim anywhere inside the grid.
 

// Example 2:

// Input:
// 4
// 0 1 2 4
// 12 13 14 9
// 15 5 11 10
// 3 6 7 8 

// Output:
// 10

#include <bits/stdc++.h>
using namespace std;

//--------Djikstra---------
int Solve(int n, vector<vector<int>> &grid) {
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({grid[0][0],{0,0}});
    vector<vector<int>> vis(n,vector<int>(n,0));
    vis[0][0]=1;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int t=it.first;
        int r=it.second.first;
        int c=it.second.second;
        if(r==n-1 && c==n-1) return t;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]){
                pq.push({max(t,grid[nr][nc]),{nr,nc}});
                vis[nr][nc]=1;
            }
        }
    }
}

//---------Binary Search----------
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0, high = n*n-1;
        while(low < high){
            int mid = low + (high - low)/2;
            vector<vector<int>> visited(n, vector<int>(n,0));
            if(reachableOrNot(mid, grid, n, 0, 0, visited)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }

    int reachableOrNot(int T, vector<vector<int>>& grid, int N, int i, int j, vector<vector<int>> &visited) {
        if(i == N-1 && j == N-1){
            return true;
        }
        visited[i][j] = true;
        for(auto dir : dirs){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(new_i >= 0 && new_i < N && new_j >= 0 && new_j < N && !visited[new_i][new_j] && grid[i][j]<=T && grid[new_i][new_j] <= T){
                if(reachableOrNot(T, grid, N, new_i, new_j, visited)){
                    return true;
                }
                
            }
        }
        return false;
    }
};


//-------------Disjoint Set---------
class Disjointset
{
private:
    vector<int> parent, size; // parent will store the parents '
                              // size will be taken to rank or compare the parent order while doing union.
public:
    Disjointset(int n)
    {
        parent.resize(n + 1);
        size.resize(n, 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i; // element will be it's parent only
        }
    }
    int find(int X)
    {
        if (parent[X] == X)
            return X;

        return parent[X] = find(parent[X]); // path compression
    }
    void UNION(int X, int Y)
    {
        int parent1 = find(X);
        int parent2 = find(Y);
        if (parent1 == parent2)
            return; // CYCLE DETECTED.
        if (size[parent1] < size[parent2])
        {
            parent[parent1] = parent2;
            size[parent2] += size[parent1];
        }
        else
        {
            parent[parent2] = parent1;
            size[parent1] += size[parent2];
        }
    }
    void printArrays()
    {
        cout << "PARENT" << endl;
        for (auto it : parent)
        {
            cout << it << " ";
        }
        cout << endl;
        cout << "SIZE" << endl;
        for (auto it : size)
        {
            cout << it << " ";
        }
    }
    int SIZE(int vertex) // returns the size of the whole disjoint set of which the current vertex is a part of.
    {
        return size[find(vertex)]; // returns the size of disjoint set that it is a part of.
    }

    int noOfdisjointSets(int n) // pass n as indexing. , gives all disjoint sets and not particular
    {
        // find the parent of all nodes.

        for (int i = 0; i < n; i++)
        {
            parent[i] = find(i);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
            {
                cnt++;
            }
        }
        return cnt;

        /*
      //   METHOD 2
        set<int> s;
        for(int i=0;i<n;i++)
        {
            s.insert(parent[i]);
        }
        return s.size();
        */
    }
};

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        return UnionAndFind_swimInWater(grid);
    }
    int UnionAndFind_swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        Disjointset ds(n * n);
        pair<int, int> locations[n * n];                // store the location of the element reachable exactly at time t.
        vector<vector<int>> vis(n, vector<int>(n, -1)); // can use grid for this purpose also.
        for (int i = 0; i < n; i++)                     // storing the locations of elements
        {
            for (int j = 0; j < n; j++)
            {
                locations[grid[i][j]] = {i, j};
            }
        }

        int delRow[] = {0, 0, 1, -1};
        int delCol[] = {1, -1, 0, 0};
        // now the time will be in range from 0 to n*n -1
        for (int time = 0; time < n * n; time++)
        {

            // find the loc of element reachable exactly at  this time {x,y}
            int x = locations[time].first;
            int y = locations[time].second;
            // mark the current as visited
            vis[x][y] = 1;
            // check if all it's neighbours, if they have already been reached then merge with it.
            for (int k = 0; k < 4; k++)
            {
                int nrow = x + delRow[k];
                int ncol = y + delCol[k];
                if (underBoundaries(nrow, ncol, n, n) && vis[nrow][ncol] == 1)
                {
                    ds.UNION(x*n+y,nrow*n+ncol);//join the locations here and not the heights.
                }
            }
            if (ds.find(0) == ds.find(n*n-1)) // if last element location in the connected component
            {
                return time;
            }
        }

        return n * n - 1; // since in max time it will be possible to reach the desired
        // the code will itself cover this situation and does not require it here only.
        /*
         some intutive improvements in the problem:
          since time is increasing linearly,
          so any element which has lesser value than current time is already visited
          so we can say element<time then already visited.
          we can save ourselves of vis extra n square space.
        */
    }
    bool underBoundaries(int nrow, int ncol, int n, int m)
    {
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
        {
            return true;
        }
        return false;
    }
};