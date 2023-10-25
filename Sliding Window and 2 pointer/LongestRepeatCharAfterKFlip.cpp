// Given a string S and an integer K. In one operation, you are allowed to choose any character of the string and change it to any other uppercase English character.You can perform this operation atmost K times.
// Return the length of the longest substring containing same letter you can get after performing the above operations.
// Note : S consists of only uppercase English letters.

// Example 1:
// S = "AABAABB"
// k = 2
// Output: 6
// Explanation: Replace the occurrence of 'B' with 'A' and form "AAAAAAB".
// The substring "AAAAAA" has the most extended repeating letters, which is 6.A' with 2 'B's or vice-versa.

#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    vector<int> mp(26,0);
    int i=0,j=0,n=s.size(),maxlen=INT_MIN,mostfreqchar=0;
    while(j<n){
        mp[s[j]-'A']++;
        mostfreqchar=max(mostfreqchar,mp[s[j]-'A']);
        int charstochange=(j-i+1)-mostfreqchar;
        if(charstochange<=k){
            maxlen=max(maxlen,j-i+1);
        }
        else{
            mp[s[i]-'A']--;
            i++;
        }
        j++;
    }
    return maxlen;
}