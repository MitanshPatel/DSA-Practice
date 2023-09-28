// Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.

// A binary string is that string which contains only 0 and 1.

// Example 1:

// Input:
// N = 3
// Output:
// 000 , 001 , 010 , 100 , 101
// Explanation:
// None of the above strings contain consecutive 1s. "110" is not an answer as it has '1's occuring consecutively.

//see ADITYA VERMA and refer my notes
#include <bits/stdc++.h>
using namespace std;

void gen(string op, int n){
    if(op.length()==n){
        cout<<op<<" ";
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back('0');
    gen(op1, n);
    if(op[op.length()-1] == '1'){
        return;
    }
    op2.push_back('1');
    gen(op2,n);
    return;
}
void generateBinaryStrings(int num){
    //Write your code
    string op="";
    gen(op, num);
}