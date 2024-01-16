// Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
// A reversal means changing '{' to '}' or vice-versa.

// Example 1:

// Input:
// S = "}{{}}{{{"
// Output: 3
// Explanation: One way to balance is:
// "{{{}}{}}". There is no balanced sequence
// that can be formed in lesser reversals.

#include <bits/stdc++.h>
using namespace std;

int countRev (string s){
    // your code here
    if(s.length()%2!=0){
        return -1;
    }
    int ansCount=0;
    stack<char>st;
    for(char ch:s){
        if(ch=='{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else st.push(ch);
        }
    }
    
    while(!st.empty()){
        char a=st.top();
        st.pop();
        char b=st.top();
        st.pop();
        if(a==b){
            ansCount +=1;
        }
        else{
            ansCount +=2;
        }
    }
    return ansCount;
}