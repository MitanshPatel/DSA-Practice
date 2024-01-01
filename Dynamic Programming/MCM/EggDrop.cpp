// You are given N identical eggs and you have access to a K-floored building from 1 to K.

// There exists a floor f where 0 <= f <= K such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break.
// There are few rules given below. 

// An egg that survives a fall can be used again.
// A broken egg must be discarded.
// The effect of a fall is the same for all eggs.
// If the egg doesn't break at a certain floor, it will not break at any floor below.
// If the eggs breaks at a certain floor, it will break at any floor above.
// Return the minimum number of moves that you need to determine with certainty what the value of f is.

// For more description on this problem see wiki page

// Example 1:

// Input:
// N = 1, K = 2
// Output: 2
// Explanation: 
// 1. Drop the egg from floor 1. If it 
//    breaks, we know that f = 0.
// 2. Otherwise, drop the egg from floor 2.
//    If it breaks, we know that f = 1.
// 3. If it does not break, then we know f = 2.
// 4. Hence, we need at minimum 2 moves to
//    determine with certainty what the value of f is.

#include <bits/stdc++.h>
using namespace std;

//--------------Recursive---------------
int Solve(int eggs, int floors) {
	if (eggs == 1)
		return floors;
	if (floors == 0 || floors == 1)
		return floors;

	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) {
		int temp_ans = 1 + max(Solve(eggs - 1, k - 1), Solve(eggs, floors - k)); // once egg break means decrement both floor and egg another agg did not break means check egg dropping from above 
		mn = min(mn, temp_ans);
	}

	return mn;
}

//------------Memoization----------------
const int D = 101;
int t[D][D];

int Solve(int eggs, int floors) {
	if (t[eggs][floors] != -1)
		return t[eggs][floors];

	if (eggs == 1 || floors == 0 || floors == 1) {
		t[eggs][floors] = floors;
		return floors;
	}

	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) {
		int temp_ans = 1 + max(Solve(eggs - 1, k - 1), Solve(eggs, floors - k));
		mn = min(mn, temp_ans);
	}

	return t[eggs][floors] = mn; // store in table for further reference 
}

//------------Optimized Memoization------------------
const int D = 101;
int dp[D][D];

int Solve(int eggs, int floors) {
	if (dp[eggs][floors] != -1) // if value is already there in the table then return the value 
		return dp[eggs][floors];

	if (eggs == 1 || floors == 0 || floors == 1) { // base condition
		dp[eggs][floors] = floors;
		return floors;
	}

	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) {
		int top, bottom;
		if (dp[eggs - 1][k - 1] != -1) // break the temp in sub problemes 
			top = dp[eggs - 1][k - 1];
		else {
			top = Solve(eggs - 1, k - 1);
			dp[eggs - 1][k - 1] = top;
		}

		if (dp[eggs][floors - k] != -1)
			bottom = dp[eggs][floors - k];
		else {
			bottom = Solve(eggs, floors - k);
			dp[eggs][floors - k] = bottom;
		}
		int temp_ans = 1 + max(top, bottom);
		mn = min(mn, temp_ans);
	}

	return dp[eggs][floors] = mn;
}

int main() {
	int eggs, floors;
	cin >> eggs >> floors;

	cout << Solve(eggs, floors) << endl;
	return 0;
}