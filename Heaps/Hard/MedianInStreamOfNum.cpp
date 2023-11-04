// Given an input stream of N integers. The task is to insert these numbers into a new stream and
// find the median of the stream formed by each insertion of X to the new stream.

// Example 1:
// Input:
// N = 4
// X[] = 5,15,1,3
// Output:
// 5
// 10
// 5
// 4
// Explanation:Flow in stream : 5, 15, 1, 3 
// 5 goes to stream --> median 5 (5) 
// 15 goes to stream --> median 10 (5,15) 
// 1 goes to stream --> median 5 (5,15,1) 
// 3 goes to stream --> median 4 (5,15,1 3) 

#include <bits/stdc++.h>
using namespace std;

priority_queue<int> s;                            // smaller
priority_queue<int, vector<int>, greater<int>> g; // greater

void insertHeap(int &x){
    if (s.empty()){
        s.push(x);
        return;
    }

    if (s.size() > g.size()){
        if (x < s.top()){
            g.push(s.top());
            s.pop();
            s.push(x);
        }
        else
            g.push(x);
    }

    else{
        if (x < s.top())
            s.push(x);

        else{
            g.push(x);
            s.push(g.top());
            g.pop();
        }
    }
}

// Function to balance heaps.
void balanceHeaps() {}

double getMedian(){
    if (s.size() == g.size())
        return (s.top() + g.top()) / 2.0;
    return s.top();
}