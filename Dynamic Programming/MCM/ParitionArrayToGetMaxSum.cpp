// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k.
// After partitioning, each subarray has their values changed to become the maximum value of that subarray.
// Return the largest sum of the given array after partitioning.

// Example 1:
// Input:
// n = 7
// k = 3
// arr = [1,15,7,9,2,5,10]
// Output:
// 84
// Explanation:
// arr becomes [15,15,15,9,10,10,10]


#include <bits/stdc++.h>
using namespace std;

//---------------Memoize------------------
int f(int ind, vector<int> &num, int k, vector<int> &dp) {
    int n = num.size();

    // Base case: If the current index is equal to the size of the array, return 0.
    if (ind == n) return 0;

    // If the result for this index is already computed, return it from dp array.
    if (dp[ind] != -1) return dp[ind];

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    // Loop through the array starting from the current index.
    for (int j = ind; j < min(ind + k, n); j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k, dp);
        maxAns = max(maxAns, sum);
    }

    // Store the computed result in the dp array and return it.
    return dp[ind] = maxAns;
}

int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();
    vector<int> dp(n, -1);
    return f(0, num, k, dp);
}

//-------------Tabular---------------
int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();
    
    // Create a DP array to store the maximum sum.
    vector<int> dp(n + 1, 0);
    
    // Iterate through the array from right to left.
    for (int ind = n - 1; ind >= 0; ind--) {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        
        // Loop through the next k elements (or remaining elements if k is smaller).
        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        
        // Store the computed maximum sum in the DP array.
        dp[ind] = maxAns;
    }
    
    // The maximum sum after partitioning the entire array is stored in dp[0].
    return dp[0];
}

int main() {
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int maxSum = maxSumAfterPartitioning(num, k);
    cout << "The maximum sum is: " << maxSum << "\n";
    return 0;
}

