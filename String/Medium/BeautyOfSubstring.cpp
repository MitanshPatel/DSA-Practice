// Given a string S, return the sum of beauty of all its substrings.
// The beauty of a string is defined as the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of string "aaac" is 3 - 1 = 2.
// Example 1:

// Input:
// S = "aaac"
// Output:
// 3
// Explanation: The substrings with non - zero beauty are ["aaac","aac"]
// where beauty of "aaac" is 2 and beauty of "aac" is 1.
 

// Example 2:

// Input:
// S = "geeksforgeeks"
// Output:
// 62
// Explanation: There are 91 substrings of the given strings.
// Like, the beauty of substring "geek" is 1.
// In this way the sum of beauties of all substrings are 62.


#include<bits/stdc++.h>
using namespace std;

//brute force
int beautySum(string s) {
        // Your code goes here
        int n=s.size(), ans=0;
        for(int i=0; i<n; i++){
            int freq[26]={0};
            for(int j=i; j<n; j++){
                int maxi=INT_MIN;
                int mini=INT_MAX;
                freq[s[j]-'a']++;
                for(int k=0;k<26; k++){
                    if(freq[k]!=0){
                        maxi=max(maxi, freq[k]);
                        mini=min(mini, freq[k]);
                    }
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }