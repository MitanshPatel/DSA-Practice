// Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i.
// Determine the maximum value obtainable by cutting up the rod and selling the pieces.
// Note: Consider 1-based indexing.

// Example 1:
// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by 
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.

#include <bits/stdc++.h>
using namespace std;

//---------Memoization-----------
class Solution{
    int t[1002][1002];
    
  public:
    int helper(int price[], int length[], int n, int i){
        if(n == 0 || i == 0) return 0; //Base case is there is no rod or there is not price then profit will be 0
        
        if(t[n][i] != -1) return t[n][i]; //Checking our cache for sub-problem
        
        if(length[n-1] <= i){
            //We can cut in current size or we cant cut in current size, Multiple sizes are allowed
            return t[n][i] = max(price[n-1]+helper(price, length, n, i-length[n-1]), helper(price, length, n-1, i));
        }
        
        //we cant cut in current size coz we dont hv enough size of rod
        else return t[n][i] = helper(price, length, n-1, i);
    }
  
    int cutRod(int price[], int n) {
        memset(t, -1, sizeof(t));
        //Creating a length array for simplicity of our approach
        int length[n];
        for(int i=0;i<n;i++) length[i] = i+1;
        return helper(price, length, n, n);
    }
};


//---------Bottom Up------------
class Solution{
  public:
    int cutRod(int price[], int n) {
        int len[n];
        for(int i=0;i<n;i++) len[i] = i + 1;
        
        int t[n+1][n+1];
        
        for(int i=0;i<n+1;i++){
            t[i][0] = 0;
            t[0][i] = 0;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(len[i-1] <= j){
                    t[i][j] = max(price[i-1]+t[i][j-len[i-1]], t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][n];
    }
};