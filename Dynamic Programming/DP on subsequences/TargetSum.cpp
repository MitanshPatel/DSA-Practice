// Given an array of integers A[] of length N and an integer target.
// You want to build an expression out of A by adding one of the symbols '+' and '-' before each integer in A and then concatenate all the integers.

// For example, if arr = {2, 1}, you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that can be built, which evaluates to target.


// Example 1:

// Input:
// N = 5
// A[] = {1, 1, 1, 1, 1}
// target = 3
// Output:
// 5
// Explanation:
// There are 5 ways to assign symbols to 
// make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int CountSubsetsWithSum(vector<int>& nums,int sum) {
       int n= nums.size();
	int t[n + 1][sum + 1]; // DP - matrix
	// initialization
	t[0][0] = 1;
	int k = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0 && j > 0)
				t[i][j] = 0;
			if (j == 0 && i > 0) {
				if (nums[i - 1] == 0) {
					t[i][j] = pow(2, k);
					k++;
				}
				else
					t[i][j] = t[i - 1][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (nums[i - 1] <= j)
				t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum];
}
    int findTargetSumWays(vector<int>& nums, int diff) {
        int n= nums.size();
        int sumOfArray = 0;
        for (int i = 0; i < n; i++)
            sumOfArray += nums[i];

        if ((sumOfArray + diff) % 2 != 0)
            return 0;
        else
            return CountSubsetsWithSum(nums, (sumOfArray + diff) / 2);
    }
};