// Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.

// Example 1:

// Input : str = "abc"
// Output: "" a ab abc ac b bc c
// Explanation : There are 8 subsequences that 
// can be formed from abc.

#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &v, string ip, string op){
    if(ip.length()==0){
        v.push_back(op);
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(v, ip, op1);
    solve(v, ip, op2);
    return;
}

vector<string> AllPossibleStrings(string s){
    // Code here
    vector<string> v;
    string op="";
    string ip=s;
    solve(v, ip, op);
    sort(v.begin(), v.end());
    return v;
}