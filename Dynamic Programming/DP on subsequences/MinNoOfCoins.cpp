// Given a value V and array coins[] of size M, the task is to make the change for V cents,
// given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins
// Find the minimum number of coins to make the change. If not possible to make change then return -1.

// Example 1:
// Input: V = 30, M = 3, coins[] = {25, 10, 5}
// Output: 2
// Explanation: Use one 25 cent coin
// and one 5 cent coin

#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX-1

//-------------Memoized----------
int helper(int coins[], int M, int V, vector<vector<int>> &t){
    //when there is no coins but we have to choose infinite number of coins, initialize to MAX value for finding MIN value
    if(M == 0) return INT_MAX - 1; 
    
    if(V == 0) return 0; //When required change is 0 then no chance to do so
    
    //This is the trick, we need to initialize the 2nd row for this problem
    if(M == 1){
        if(V % coins[0] == 0) return V / coins[0];
        else return INT_MAX - 1;
    }
    
    //checking for answer of our sub problem in our chache mem.
    if(t[M][V] != -1) return t[M][V];
    
    //Like, unbounded knapsacks we can take multiple occurances to, and '+1' for counting the number of coins, so futher we can make it minimum
    if(coins[M-1] <= V) return t[M][V] = min(helper(coins, M, V-coins[M-1], t) + 1, helper(coins, M-1, V, t));
    
    //It is grater than out requiremen, so we can't take it lets move to the next coin now
    else return t[M][V] = helper(coins, M-1, V, t);
}

int minCoins(int coins[], int M, int V) 
{ 
    vector<vector<int>> t(M+1, vector<int> (V+1, -1));
    int ans = helper(coins, M, V, t);
    if(ans == INT_MAX - 1) return -1; //if it is not possible to change the coin then return '-1'
    return ans; //else return the valid answer
} 


int getMinNumberOfCoins(int coins[], int n, int sum) {
	int t[n + 1][sum + 1];
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j == 0)
				t[i][j] = 0;
			if (i == 0)
				t[i][j] = INF;
			if (i == 1) {
				if (j % coins[i - 1] == 0)
					t[i][j] = j / coins[i - 1];
				else
					t[i][j] = INF;
			}
		}
	}

	t[0][0] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= sum; j++)
			if (coins[i - 1] <= j)
				t[i][j] = min(t[i - 1][j], 1 + t[i][j - coins[i - 1]]);
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

	cout << getMinNumberOfCoins(coins, n, sum) << endl;
	return 0;
}
	  
