// Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

// Matrix [r+1] [c]
// Matrix [r+1] [c-1]
// Matrix [r+1] [c+1]
// Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

// NOTE: We can start from any column in zeroth row and can end at any column in (N-1)th row.

// Example 1:

// Input: N = 2
// Matrix = {{348, 391},
//           {618, 193}}
// Output: 1009
// Explaination: The best path is 391 -> 618. 
// It gives the sum = 1009.

#include <bits/stdc++.h>
using namespace std;

//-----------------Recursive-------------------
int helper(int i, int j, int N, vector<vector<int>> Matrix){
    if(j < 0 || j >= N) return -1e9;
    if(i == 0) return Matrix[0][j];
    
    int up = Matrix[i][j] + helper(i-1, j, N, Matrix);
    int ld = Matrix[i][j] + helper(i-1, j-1, N, Matrix);
    int rd = Matrix[i][j] + helper(i-1, j+1, N, Matrix);
    
    return max(up, max(ld, rd));
}

int maximumPath(int N, vector<vector<int>> Matrix){
    int maxi = INT_MIN;
    
    for(int j=0;j<N;j++){
        int ans = helper(N-1, j, N, Matrix);
        maxi = max(maxi, ans);
    }
    return maxi;
}

//--------------Memoization---------------------
int helper(int i, int j, int N, vector<vector<int>> &Matrix, vector<vector<int>> &dp){
    if(j < 0 || j >= N) return -1e9;
    if(i == 0) return Matrix[0][j];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = Matrix[i][j] + helper(i-1, j, N, Matrix, dp);
    int ld = Matrix[i][j] + helper(i-1, j-1, N, Matrix, dp);
    int rd = Matrix[i][j] + helper(i-1, j+1, N, Matrix, dp);
    
    return dp[i][j] = max(up, max(ld, rd));
}

int maximumPath(int N, vector<vector<int>> Matrix){
    vector<vector<int>> dp(N, vector<int> (N, -1));
    
    int maxi = INT_MIN;
    
    for(int j=0;j<N;j++){
        int ans = helper(N-1, j, N, Matrix, dp);
        maxi = max(maxi, ans);
    }
    return maxi;
}

//---------------Tabulation----------------
int maximumPath(int N, vector<vector<int>> Matrix){
    vector<vector<int>> dp(N, vector<int> (N, 0));
    
    for(int j=0;j<N;j++) dp[0][j] = Matrix[0][j];
    
    for(int i=1;i<N;i++){
        for(int j=0;j<N;j++){
            int up = Matrix[i][j] + dp[i-1][j];
            
            int ld = Matrix[i][j];
            (j >= 0)? ld += dp[i-1][j-1] : ld += -1e9;
            
            int rd = Matrix[i][j];
            (j+1 < N)? rd += dp[i-1][j+1] : rd += -1e9;
            
            dp[i][j] = max(up, max(ld, rd));
        }
    }
    
    int maxi = INT_MIN;
    
    for(int j=0;j<N;j++){
        maxi = max(maxi, dp[N-1][j]);
    }
    return maxi;
}