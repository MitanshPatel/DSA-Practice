// Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.
//  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
// Note : All characters are in Lowercase alphabets. 

// Example 1:

// Input:
// S = "timetopractice"
// P = "toc"
// Output: 
// toprac
// Explanation: "toprac" is the smallest
// substring in which "toc" can be found.

#include<bits/stdc++.h>
using namespace std;

string smallestWindow (string s, string t){
    int start_idx=0,len=INT_MAX;
    vector<int> tm(26,0);
    
    for(int i=0;i<t.size();i++){
        tm[t[i]-'a']++;
    }
    int need=0;
    for(int i=0;i<26;i++){
        if(tm[i]!=0)
            need++;
    }
    int have=0;
    vector<int> sm(26,0);
    int i=0;
    for(int j=0;j<s.size();j++){
        sm[s[j]-'a']++;
        if(tm[s[j]-'a']==sm[s[j]-'a'])
        have++;
        while(have==need){
            if(len>(j-i+1)){
                len=j-i+1;
                start_idx=i;
            }
            sm[s[i]-'a']--;
            if(tm[s[i]-'a']>sm[s[i]-'a'])
                have--;
            i++;
        }
    }
    if(len==INT_MAX)return "-1";
    string ans=s.substr(start_idx,len);
    return ans;
}