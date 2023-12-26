// Given two strings str1 and str2. The task is to remove or insert the minimum number of characters
// from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted
// from one point of str1 and inserted to some another point.

// Example 1:
// Input: str1 = "heap", str2 = "pea"
// Output: 3
// Explanation: 2 deletions and 1 insertion p and h deleted from heap. Then, p is 
// inserted at the beginning One thing to note, though p was required yet it was 
// removed/deleted first from its position and then it is inserted to some other 
// position. Thus, p contributes one to the deletion_count and one to the insertion_count.

#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

void MinInsertDel(string X, string Y, int n, int m) {
	int lcs_len = LCS(X, Y, n, m);
	cout << "Minimum number of deletions = " << (n - lcs_len)<<endl;
  cout << "Minimum number of insertions = " << (m - lcs_len)<<endl;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	MinInsertDel(X, Y, n, m);
	return 0;
}