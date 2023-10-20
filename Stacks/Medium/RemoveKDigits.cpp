// Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
// Note : The given num does not contain any leading zero.

// Example 1:

// Input:
// S = "149819", K = 3
// Output: 119
// Explanation: Remove the three digits 
// 4, 9, and 8 to form the new number 119
// which is smallest.

#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string S, int K) {
    if(K>=S.size()){
        return "0";
    }
    string ans="";
    stack<char>st;
    for(int i=0;i<S.size();i++){
            while(!st.empty() and K>0 and st.top()>S[i]){
            st.pop();
            K--;
        }
        
        if(!st.empty() or S[i]!='0'){  //when stack empty then can't insert 0
            st.push(S[i]);
        }
        
    }
    while(K>0 and !st.empty()){
        st.pop();
        K--;
    }
    if(st.empty()){
        return "0";
    }
    else{
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}