// Given strings str1 and str2, find the minimum (contiguous) substring W of str1, so that str2 is a subsequence of W.

// If there is no such window in str1 that covers all characters in str2, return the empty string "".
// If there are multiple such minimum-length windows, return the one with the left-most starting index.
 
// Example 1:
// Input: 
// str1: geeksforgeeks
// str2: eksrg
// Output: 
// eksforg
// Explanation: 
// Eksforg satisfies all required conditions. str2 is its subsequence and it is longest and leftmost among all possible valid substrings of str1.

#include<bits/stdc++.h>
using namespace std;

string minWindow(string str1, string str2) {
    // Write your Code here
    int s2 = str2.length();
    int s1 = str1.length();
    int k = 0;
    int len = INT_MAX,last = -1;
    string ans = "";
    for(int i = 0;i<s1;i++){
        k = 0;
        int j = last + 1;
        while(j < s1 && k < s2){
            if(k < s2 && str1[j] == str2[k] ){
                if(k == 0) last = j;
                k++;
            }
            if(k == (s2) && len > (j - last + 1)){
                len = min(len,j - last + 1);    
                ans = str1.substr(last,j-last+1);
            }
            j++;
        }
    }
    
    return ans;
}