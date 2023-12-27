// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome.
// Determine the fewest cuts needed for palindrome partitioning of the given string.

// Example 1:
// Input: str = "ababbbabbababa"
// Output: 3
// Explaination: After 3 partitioning substrings 
// are "a", "babbbab", "b", "ababa".

#include <bits/stdc++.h>
using namespace std;

int t[501][501]; //Cache memory for fast response

// Just a normal function for checking palindrome
bool isPalin(string &s, int i, int j){
    while(i <= j){
        if(s[i++] != s[j--]) return false;
    }
    return true;
}

//---------------Memoization------------------
int helper(string &s, int i, int j){
    if(i >= j) return 0; // If there are no elements, then no partition needed.
    
    if(t[i][j] != -1) return t[i][j]; // If subproblem is already calculated, then that from there
    
    if(isPalin(s, i, j)) return 0; // If already is a palindrome, then no need to partitioning.
    
    int mini = INT_MAX; // Mini variable for calculating, the minimum value
    
    // Checking for all possibilities of partitioning, like - MCM
    for(int k=i;k<=j-1;k++){
        // increament by '1', for the track the no. of partition
        int ans = 1 + helper(s, i, k) + helper(s, k+1, j);
        
        // Update Minimum Variable
        mini =min(mini, ans);
    }
    return t[i][j] = mini; // Store and return our answer
}


//-------------Optimized Memoization-----------------
int helper(string &s, int i, int j){
    if(i >= j) return 0; // If there are no elements, then no partition needed.
    
    if(t[i][j] != -1) return t[i][j]; // If subproblem is already calculated, then that from there
    
    if(isPalin(s, i, j)) return 0; // If already is a palindrome, then no need to partitioning.
    
    int mini = INT_MAX; // Mini variable for calculating, the minimum value
    
    // Checking for all possibilities of partitioning, like - MCM
    for(int k=i;k<=j-1;k++){
        // increament by '1', for the track the no. of partition
        int left = 0, right = 0;
        
        if(t[i][k] != -1) left = t[i][k];
        else{
            left = helper(s, i, k);
            t[i][k] = left;
        }
        
        if(t[k+1][j] != -1) right = t[k+1][j];
        else{
            right = helper(s, k+1, j);
            t[k+1][j] = right;
        }
        
        int ans = 1 + left + right;
        
        // Update Minimum Variable
        mini = min(mini, ans);
    }
    return t[i][j] = mini; // Store and return our answer
}

//----------REcursive (Striver)----------
// Recursive function to find the minimum number of partitions to make palindromes.
int minPartitions(int i, int n, string &str) {
    // Base case: If we've reached the end of the string.
    if (i == n) return 0;

    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++) {
        if (isPalin(str,i, j)) {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + minPartitions(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

//-------------Bottom Up Tabulation--------------- (Striver)
// Function to find the minimum number of partitions for palindrome partitioning.
int palindromePartitioning(string str) {
    int n = str.size();
    // Create a DP array to store the minimum number of partitions.
    vector<int> dp(n + 1, 0);
    dp[n] = 0; // Initialize the last element to 0.

    // Loop through the string in reverse order.
    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        // Consider all possible substrings starting from the current index.
        for (int j = i; j < n; j++) {
            if (isPalin(str,i, j)) {
                // If the substring is a palindrome, calculate the cost and minimize it.
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    // Subtract 1 as it counts partitions, not cuts.
    return dp[0] - 1;
}