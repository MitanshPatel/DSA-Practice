// Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations
// of well-formed(balanced) parentheses.

// Example 1:

// Input:
// N = 3
// Output:
// ((()))
// (()())
// (())()
// ()(())
// ()()()

#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, string op, vector<string> &v){
    if(open==0 && close==0){
        v.push_back(op);
        return;
    }
    if(open!=0){
        string op1=op;
        op1.push_back('(');
        solve(open-1, close, op1, v);
    }
    if(close>open){
        string op2=op;
        op2.push_back(')');
        solve(open, close-1, op2, v);
    }
    return;
}

vector<string> AllParenthesis(int n) 
{
    // Your code goes here 
    int open=n;
    int close=n;
    string op="";
    vector<string> v;
    solve(open, close, op, v);
    return v;
}