// We are given an integer array asteroids of size N representing asteroids in a row. For each asteroid, the absolute value represents its size,
// and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode.
// If both are of same size, both will explode. Two asteroids moving in the same direction will never meet.
 
// Example 1:
// Input:
// N = 3
// asteroids[ ] = {3, 5, -3}
// Output: {3, 5}
// Explanation: The asteroid 5 and -3 collide resulting in 5. The 5 and 3 never collide.

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(int N, vector<int> &asteroids) {
    stack<int> st;
    vector<int> ans;

    int i = 0;
    while(i < N){
        if(st.empty()){
            st.push(asteroids[i]);
            ++i;
        }
        else{
            if((asteroids[i] > 0 && st.top() > 0) || 
            (asteroids[i] < 0 && st.top() < 0) ||
            (asteroids[i] > 0 && st.top() < 0)){
                st.push(asteroids[i]);
                i++;
            }
            else if(asteroids[i] < 0 && st.top() > 0){
                if( st.top() == abs(asteroids[i])){
                    st.pop();
                    i++;
                }
                else if(st.top()> abs(asteroids[i])){
                    i++;
                }
                else{
                    while(!st.empty() && st.top()>0 && st.top() < abs(asteroids[i])){
                        st.pop();
                    }
                }
            }
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}