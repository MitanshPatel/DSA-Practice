// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

// The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

// Example 1:

// Input: N = 5
// arr = {40, 20, 30, 10, 30}
// Output: 26000
// Explanation: There are 4 matrices of dimension 
// 40x20, 20x30, 30x10, 10x30. Say the matrices are 
// named as A, B, C, D. Out of all possible combinations,
// the most efficient way is (A*(B*C))*D. 
// The number of operations are -
// 20*30*10 + 40*20*10 + 40*10*30 = 26000.

#include <bits/stdc++.h>
using namespace std;

//------------Recursive-------------
int Solve(int arr[], int i, int j) {
	if (i >= j)
		return 0;

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, temp_ans); // take temp minimum value from the temp answers
	}

	return ans;
}

const int D = 1000;
int t[D][D];
//-----------Memoization--------------
int Solve(int arr[], int i, int j) {
	if (i >= j) {
		t[i][j] = 0;
		return 0;
	}

	if (t[i][j] != -1)// when it is not zero means return the value from the table other than -1
		return t[i][j]; 

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, temp_ans);
	}

	return t[i][j] = ans; // store it in table 
}

//----------------Bottom Up------------------
int matrixMultiplication(int N, int arr[]){
    vector<vector<int>> dp(N, vector<int> (N,0));
    for(int i=0; i<N; i++) dp[i][i] = 0;
    
    for(int i=N-1; i>=1; i--){ 
        for(int j=i+1; j<N; j++){
            int mini = 1e9;
            for(int k=i; k<j; k++){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini,steps);
            }
            dp[i][j] = mini;
        }
    }
    return(dp[1][N-1]);
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(t, -1, sizeof(t));

	cout << Solve(arr, 1, n - 1) << endl;
	return 0;
}