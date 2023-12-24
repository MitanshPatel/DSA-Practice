// Given two strings, find the length of longest subsequence present in both of them.
// Both the strings are in uppercase latin alphabets.

// Example 1:
// Input:
// A = 6, B = 6
// str1 = ABCDGH
// str2 = AEDFHR
// Output: 3
// Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.

#include <bits/stdc++.h>
using namespace std;

//----------Recursion--------------
int LCS(string X, string Y, int n, int m) {
	// base case
	if (n == 0 || m == 0)
		return 0;

  // choice diagram
	// when both string X and Y is having same last char
	if (X[n - 1] == Y[m - 1])
		return 1 + LCS(X, Y, n - 1, m - 1); // count the number and decreament the both's string length
	// when both string's last character is not same 
	else
		return max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1)); // one take full and another by leaving last and vice versa 
}

//-----------Memoization----------
int dp[1000][1000];
int LCS(string X, string Y, int n, int m) {
	// base case
	if (n == 0 || m == 0)
		dp[n][m] = 0;

	if (dp[n][m] != -1) // when table is not having -1 then return the value which is preseent in that block
		return dp[n][m];

  // choice diagram 
	// when last character is same
	if (X[n - 1] == Y[m - 1])
		dp[n][m] = 1 + LCS(X, Y, n - 1, m - 1);// count the number and decreament the both's string length // store the value in particular block 
	// when last character is not same -> pick max
	else
		dp[n][m] = max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1)); // one take full and another by leaving last char and vice versa // store the value in particular block 

	return dp[n][m];
}

//-------Bottom Up------------
int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// initialize 1st row and of dp matrix with 0 according to the base condition of recursion // base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;
// choise diagram is used to fill rest of the matrix 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m]; // last row and last column element will give the length of the LCS;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}