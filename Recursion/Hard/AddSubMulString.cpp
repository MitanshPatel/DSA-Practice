// Given a string S that contains only digits (0-9) and an integer target, return all possible strings to insert the binary operator ' + ', ' - ', or ' * ' between the digits of S so that the resultant expression evaluates to the target value.
// Note:
// Operands in the returned expressions should not contain leading zeros. For example, 2 + 03 is not allowed whereas 20 + 3 is fine. It is allowed to not insert any of the operators.
// If no solution is found, return an empty string array.

// Input:
// S = "123"
// target = 6
// Output: { "1*2*3", "1+2+3"}
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

// Example 3:

// Input:
// S = "12"
// target = 12
// Output: { "12"} 
// Explanation: S itself matches the target. No other strings are possible.

#include <bits/stdc++.h>
using namespace std;

void solve(int ind,string s,int target,vector<string> &ans,string op,long long prev,long long sum){
    //Base case when the index becomes equal to the size of the given string
    if(ind==s.size()){
        //iff sum==target then only we push the temporary path to the ans
        if(sum==target)
        ans.push_back(op);
        return;
    }
    //this is used for the case "1+23" for that we should require another string for the for loop
    string st="";
    //this is used to get the value of the numbers taken from the string
    long long curr=0;
    for(int i=ind;i<s.size();i++){
        //this is the case for any leading 0s in which we have to do nothing just break
        if(i>ind && s[ind]=='0')
        break;
        //preparation of the strings that are taken in each iteration
        st+=s[i];
        //conversion of prepared string to number for further computation,
        //we are using stoll since the value can be really greater
        curr=stoll(st);
        
        //if its first index to be taken, then there is only one case that it is to be taken
        if(ind==0)
        solve(i+1,s,target,ans,op+st,curr,curr);
        
        //apart from the first index, there are three cases
        else{
            solve(i+1,s,target,ans,op+"+"+st,curr,sum+curr);
            solve(i+1,s,target,ans,op+"-"+st,-curr,sum-curr);
            
            //bodmass rule comes in picture while doing multiplication, for this only we were storing the previous value
            solve(i+1,s,target,ans,op+"*"+st,prev*curr,sum-prev+prev*curr);
        }
    }
    return;
}

vector<string> addOperators(string s, int target) {
    //to store the result that is vector of strings
    vector<string> ans;
    
    //to store the temporary path that will be created in the recursive calls
    string op="";
    
    //this is used to handle the "*" case since in bodmass first the multiplication is done before "+" or "-"
    long long prev=0;
    
    solve(0,s,target,ans,op,prev,0);
    
    return ans;
}
