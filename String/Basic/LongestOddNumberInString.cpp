// Given an string S, representing a large interger. Return the largest-valued odd integer (as a string) that is substring of the given string S.


// Note : A substring is a contiguous sequence of characters within a string. Null string ("") is also a substring.

// Example 1:

// Input: s = "123504"
// Output: "1235"

#include <bits/stdc++.h>
using namespace std;

 string maxOdd(string s) {
        // your code here
        string ans;
        int k=-1;
        for(int i=s.size()-1; i>=0; i--){
            //s[i]=='1' || s[i]=='3'||s[i]=='7'||s[i]=='9'|| s[i]=='5'
            if((int(s[i]) - '0')%2==1){
                k=i;
                break;
            }
        }
        
        ans=s.substr(0, k+1);
        return ans;
    }