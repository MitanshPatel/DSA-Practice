// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Examples:
// Input Format:["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
// [
// [ ], [-2], [0], [-3], [ ], [ ], [ ], [ ]
// ]

// Result: [null, null, null, null, -3, null, 0, -2]
// Explanation: 
// stack < long long > st
// st.push(-2); Push element in stack
// st.push(0); Push element in stack
// st.push(-3); Push element in stack
// st.getMin(); Get minimum element fromstack
// st.pop(); Pop the topmost element
// st.top(); Top element is 0
// st.getMin(); Minimum element is -2

#include <bits/stdc++.h>
using namespace std;


//------no SC-----
class MinStack{
    stack<long long> st;
    long long mini;
public:
    /** initialize your data structure here. */
    MinStack(){
        while (st.empty() == false)
            st.pop();
        mini = INT_MAX;
    }

    int getMin(){
        return mini;
    }

    void push(int value)
    {
        long long val = value;
        if (st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if (val < mini){
                st.push(2 * val * 1LL - mini);
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }

    void pop(){
        if (st.empty())
            return;
        long long el = st.top();
        st.pop();

        if (el < mini){
            mini = 2 * mini - el;
        }
    }

    int top(){
        if (st.empty())
            return -1;

        long long el = st.top();
        if (el < mini)
            return mini;
        return el;
    }
};


//----using extra stack----
class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};