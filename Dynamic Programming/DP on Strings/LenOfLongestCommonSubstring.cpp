// Given two strings. The task is to find the length of the longest common substring.

// Example 1:
// Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
// Output: 4
// Explanation: The longest common substring
// is "CDGH" which has length 4.

#include <bits/stdc++.h>
using namespace std;

//--------Recursive--------
int lcs(string X, string Y, int i, int j, int count){
    if (i == 0 || j == 0)
        return count;
 
    if (X[i - 1] == Y[j - 1]) {
        count = lcs(X, Y,i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs(X, Y,i, j - 1, 0),
                    lcs(X, Y,i - 1, j, 0)));
    return count;
}

//---------Memoized--------
int t[1001][1001]; //declaring our cache
int maxi = 0; //taking a maxi variable for finding the longest size

int helper(string &S1, string &S2, int n, int m){
    //if anyoun of them is empty then return 0, con substring can form with empty string
    if(n == 0 || m == 0) return 0;
    
    //if subproblem is already calculated then return it
    if(t[n][m] != -1) return t[n][m];
    
    if(S1[n-1] == S2[m-1]){
        // if its common then we can take current element
        t[n][m] = 1 + helper(S1, S2, n-1, m-1);
        
        //update out max size of LCSS
        maxi = max(maxi, t[n][m]);
    }
    else{
        //if not matching then update the size of the string 0
        t[n][m] = 0;
    }
    
    helper(S1, S2, n-1, m); //traverse futher string
    helper(S1, S2, n, m-1); //traverse futher string
    return t[n][m];
}



//-----------Bottom Up------------
int LCSubstr(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix
    int mx = INT_MIN;
  // base condition 
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0; //
    
  // choice diagram 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]){ // when both string's last char is same
				dp[i][j] = 1 + dp[i - 1][j - 1]; // count the number and decrement the table 
                mx = max(mx, dp[i][j]);
            }
			else
				dp[i][j] = 0; // variation from LCS(DP)
	return mx;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCSubstr(X, Y, n, m) << endl;
	return 0;
}
