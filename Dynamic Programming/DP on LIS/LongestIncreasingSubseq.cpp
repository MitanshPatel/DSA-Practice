// Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

// Example 1:

// Input:
// N = 16
// A = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
// Output: 
// 6
// Explanation:
// There are more than one LIS in this array. One such Longest increasing subsequence is {0,2,6,9,13,15}.

#include <bits/stdc++.h>
using namespace std;

//-----------------Memoization--------------------
int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>>& dp) {
    // Base condition
    if (ind == n)
        return 0;
        
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
    
    int take = 0;
    
    if (prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n) {
    // Create a 2D DP array initialized to -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    return getAns(arr, n, 0, -1, dp);
}

//-----------------Tabulation--------------
int longestIncreasingSubsequence(int arr[], int n){
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
            int notTake = 0 + dp[ind+1][prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                
                take = 1 + dp[ind+1][ind+1];
            }
    
            dp[ind][prev_index+1] = max(notTake,take);
            
        }
    }
    
    return dp[0][0];
}

//------------Space Optimization---------------------
int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> next(n+1,0);
    
    vector<int> cur(n+1,0);
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
            int notTake = 0 + next[prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                
                take = 1 + next[ind+1];
            }
    
            cur[prev_index+1] = max(notTake,take);
        }
        next = cur;
    }
    
    return cur[0];
}

//----------Algo Based----------------
int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> dp(n,1);
    
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i]){
                dp[i] = max(dp[i], 1 + dp[prev_index]);
            }
        }
    }
    
    int ans = -1;
    
    for(int i=0; i<=n-1; i++){
        ans = max(ans, dp[i]);
    }
    
    return ans;
}

//-----------------Binary Search-------------
int longestIncreasingSubsequence(int arr[], int n) {
    // Create a temporary vector to store the increasing subsequence
    vector<int> temp;
    temp.push_back(arr[0]);

    int len = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > temp.back()) {
            // If arr[i] is greater than the last element of temp, extend the subsequence
            temp.push_back(arr[i]);
            len++;
        } else {
            // If arr[i] is not greater, replace the element in temp with arr[i]
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return len;
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(arr, n);
    
    return 0;
}