// Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. 
//Each dictionary word can be used more than once. Return all such possible sentences.

// Follow examples for better understanding.

// Example 1:

// Input: s = "catsanddog", n = 5 
// dict = {"cats", "cat", "and", "sand", "dog"}
// Output: (cats and dog)(cat sand dog)
// Explanation: All the words in the given 
// sentences are present in the dictionary.

// Input: s = "catsandog", n = 5
// dict = {"cats", "cat", "and", "sand", "dog"}
// Output: Empty
// Explanation: There is no possible breaking 
// of the string s where all the words are present 
// in dict.

#include <bits/stdc++.h>
using namespace std;

void solve(int n , unordered_set<string>temp,string s, int index, vector<string>&ans, string res){
    if(index==s.size()){
        res.pop_back();  //to pop the last extra space " "
        ans.push_back(res);
        return;
    }
    string v="";
    for(int i=index; i<s.length(); i++){
        v+=s[i];
        if(temp.find(v)!=temp.end()){  //to check if the left substr is present in dict or not, if it is found, call recursion for right substr
            solve(n,temp,s,i+1,ans,res+v+" ");
        }
    }
    return ;
}

vector<string> wordBreak(int n, vector<string>& dict, string s){
    vector<string>ans;
    unordered_set<string>temp;
    for(int i=0; i<dict.size(); i++){
        temp.insert(dict[i]);
    }
    solve(n,temp,s,0,ans,"");
    return ans;
}