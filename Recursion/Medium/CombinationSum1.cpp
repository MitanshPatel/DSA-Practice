// Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target.
// You may return the combinations in any order.
// The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.


// Example 1:

// Input: array = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
//              7 is a candidate, and 7 = 7.
//              These are the only two combinations.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(vector<vector<int>> &ans, vector<int> a, int b, int idx, vector<int> op){
        if(idx==a.size()){   //base caser
            if(b==0){  //only take when all el in op add to the tgt b
                ans.push_back(op);
                return;
            }
            return;
        }
        if(a[idx]<=b){   //pick the element if this condn is satisfied
            op.push_back(a[idx]);  //el is picked
            solve(ans, a, b-a[idx], idx, op);  //decrease tgt b as el is chosen, don't increase idx, as unlimited times it can be chosen
            op.pop_back();  //remove the el after it returns;
        }
        solve(ans, a ,b, idx+1, op);   //don't pick, icrease idx
        return;
    }
    vector<vector<int> > combinationSum(vector<int> &a, int b) {
        // Your code here
        
        set<int> st(a.begin(), a.end());
        vector<int> aUniq(st.begin(), st.end());  //make all el unique
        sort(aUniq.begin(), aUniq.end());  //sort it
        vector<vector<int>> ans;
        vector<int> op;
        solve(ans, aUniq, b, 0,op);
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> v{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = obj.combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}