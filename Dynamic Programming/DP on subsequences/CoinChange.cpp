// Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].  
// Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.

// Example 1:

// Input:
// N = 3, sum = 4
// coins = {1,2,3}
// Output: 4
// Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.

#include <bits/stdc++.h>
using namespace std;

//--------Recursive----------
long long int count(int coins[], int N, int sum){
    if (sum == 0) {
        return 1;
    }

    if (sum < 0 || N <= 0) {
        return 0;
    }

    long long int take = count(coins, N, sum - coins[N - 1]);
    long long int notake = count(coins, N - 1, sum);

    return take + notake;
}

//-------Memoized------
long long solve(int coins[], int N, int sum, vector<vector<long long int>>&vis){
    if (sum == 0) {
        return 1;
    }

    if (sum < 0 || N <= 0) {
        return 0;
    }
    
    if(vis[N-1][sum]!=-1){
        return vis[N-1][sum];
    }

    long long int take = solve(coins, N, sum - coins[N - 1],vis);
    long long int notake = solve(coins, N - 1, sum,vis);

    return vis[N-1][sum]=take + notake;
}
  
long long int count(int coins[], int N, int sum){
    vector<vector<long long int>>vis(N,vector<long long int>(sum+1,-1));
    return solve(coins,N,sum,vis);
}

//-------Bottom Up-----------
int getMaxNumberOfWays(int coins[], int n, int sum) {
	int t[n + 1][sum + 1];
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0)
				t[i][j] = 0;
			if (j == 0)
				t[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= sum; j++)
			if (coins[i - 1] <= j)
				t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
			else
				t[i][j] = t[i - 1][j];

	return t[n][sum];
}

signed main() {
	int n; cin >> n;
	int coins[n];
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	int sum; cin >> sum;

	cout << getMaxNumberOfWays(coins, n, sum) << endl;
	return 0;
}