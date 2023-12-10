// The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph.
// The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. 
// If Matrix[i][j]=-1, it means there is no edge from i to j.

// Input Format: 
// matrix[][] = { {0, 2, -1, -1},
//         {1, 0, 3, -1},{-1, -1, 0, -1},{3, 5, 4, 0} }

// Result:
// 0 2 5 -1 
// 1 0 3 -1 
// -1 -1 0 -1 
// 3 5 4 0 
// Explanation: In this example, the final matrix 
// is storing the shortest distances. For example, matrix[i][j] is 
// storing the shortest distance from node i to j.

#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix){
    int n=matrix.size();
    // Simple make the -1 to infinity and diagonal zeroes because shortest path for itself is zero:
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1) matrix[i][j]=1e9;
            if(i==j) matrix[i][j]=0;
        }
    }   
        
    // Main logic of floyd Warshall Algorithm:
    for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=min(matrix[i][j], (matrix[i][via]+matrix[via][j]));
            }
        }
    }
            
    // This code is used to check the negative cylce present in the matrix or not:
    // for(int i=0;i<n;i++){
    //     if(matrix[i][i]<0) cout<<"Negative cylce present.";
    // }
    
    
    // Simple converting the remaing infinity in to -1 because according to question:
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1e9) matrix[i][j]=-1;
        }
    }
}


        