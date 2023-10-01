// Find all valid combinations of K numbers that sum upto to N such that the following conditions are true:
// Only number 1 through 9 are used.
// Each number is used atmost once.
// Return the list of all possible valid combinations.
// The list must not contain the same combination twice, and the combinations returned in any order.
 
// Example 2:
// Input:
// K = 3
// N = 9
// Output: { {1, 2, 6}, {1, 3, 5}, {2, 3, 4} }
// Explanation: 
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.

#include <bits/stdc++.h>
using namespace std;

void solve(int idx, int k, int sum, vector<vector<int>> &ans, vector<int> op){
    if(k==0){
        if(sum==0){
            ans.push_back(op);
            return;
        }
        return;
    }
    for(int i=idx; i<10; i++){
        if(i > sum) break;
        op.push_back(i);
        solve(i+1, k-1, sum-i, ans, op);
        op.pop_back();
    }
}
vector<vector<int>> combinationSum(int k, int n) {
    // code here
    vector<vector<int>> ans;
    vector<int> op;
    solve(1,k, n, ans, op);
    return ans;
}