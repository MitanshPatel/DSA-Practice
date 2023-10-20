// A celebrity is a person who is known to all but does not know anyone at a party. 
// If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  
// is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.

// Example 1:
// Input:
// N = 3
// M[][] = {{0 1 0},
//          {0 0 0}, 
//          {0 1 0}}
// Output: 1
// Explanation: 0th and 2nd person both
// know 1. Therefore, 1 is the celebrity. 

#include <bits/stdc++.h>
using namespace std;

    int celebrity(vector<vector<int> >& M, int n) {
        // Optimisation using stack
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }

        while(st.size() != 1){
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();
            if(M[A][B] == 1){
                // A cant ne the celebrity
                st.push(B);
            }
            else {
                st.push(A);
            }
        }
        
        int Celebrity = st.top();
        st.pop();
        
        // Check for all rows -> Celebrity doesnt know anyone
        for(int i=0;i<n;i++){
            if(M[Celebrity][i] != 0){
                return -1;
            }
        }
        // Check for all cols -> All knows celebrity
        for(int i=0;i<n;i++){
            if(i != Celebrity && M[i][Celebrity] != 1){
                return -1;
            }
        }
        return Celebrity;
    }