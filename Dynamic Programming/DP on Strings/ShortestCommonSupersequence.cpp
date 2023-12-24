// Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
// Note: X and Y can have both uppercase and lowercase letters.

// Example 1

// Input:
// X = abcd, Y = xycd
// Output: 6
// Explanation: Shortest Common Supersequence
// would be abxycd which is of length 6 and
// has both the strings as its subsequences.

#include <bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string x, string y, int m, int n)
{
    vector<vector<int>> dp(m+1, vector<int> (n+1,0));
    for (int i = 1; i<=m; i++) {
        for (int j = 1; j<=n; j++) {
            if (x[i-1] == y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return m+n-dp[m][n];
}