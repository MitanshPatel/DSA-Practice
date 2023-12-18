// Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

// Example 1:
// Input:
// N = 6
// arr[] = {3, 34, 4, 12, 5, 2}
// sum = 9
// Output: 1 
// Explanation: Here there exists a subset with
// sum = 9, 4+3+2 = 9.

#include <bits/stdc++.h>
using namespace std;

// Aditya Verma's All the three approaches
class Solution{   
    public:
    // *********Recursive Approach*********
    bool healer(vector<int>arr, int n, int sum){
        if( sum==0 )    return true;
        if( n==0 )  return false;
        if( arr[n-1] <= sum )
            return healer( arr, n-1, sum-arr[n-1] ) or healer( arr, n-1, sum );
        else
            return healer( arr, n-1, sum );
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return healer( arr, n, sum );
    }
    
    
    // was getting segmentation fault if i use array matrix I dont why thats why i used vector
    // Now its going fine ????
    // *********Recursion + Memoization*********
    bool healer(vector<int>arr, int n, int sum, vector<vector<int>>& dp){
        if( sum==0 )    return true;
        
        if( n==0 )  return false;
        
        if( dp[n-1][sum] != -1 )
            return dp[n-1][sum];
            
        if( arr[n-1] <= sum )
            return dp[n-1][sum] = healer( arr, n-1, sum-arr[n-1], dp ) or healer( arr, n-1, sum, dp );
        else if( arr[n-1] > sum )
            return dp[n-1][sum] = healer( arr, n-1, sum, dp );
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return healer( arr, n, sum, dp );
    }

    // *********DP*********
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)    dp[i][j]= false;
                if(j==0)    dp[i][j]=true;
            }
        }
        for( int i=1; i<n+1; i++ ){
            for( int j=1; j<sum+1; j++ ){
                if( arr[i-1] <= j ){
                    dp[i][j] = dp[i-1][ j-arr[i-1] ] or dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};