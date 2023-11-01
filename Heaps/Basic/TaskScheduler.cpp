// Given a character array tasks of size N, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
// CPU has a cooldown period for each task. CPU can repeat a task only after atleast K units of time has passed after it did same task last time. It can perform other tasks in that time, can stay idle to wait for repeating that task.

// Return the least number of units of times that the CPU will take to finish all the given tasks.

// Example 1:

// Input:
// N = 6
// K = 2
// task[ ] = {'A', 'A', 'A', 'B', 'B', 'B'}
// Output: 8
// Explanation: 
// A -> B -> idle -> A -> B -> idle -> A -> B
// There is atleast 2 units of time between any two same tasks.

#include <bits/stdc++.h>
using namespace std;

//------------using heap------------------
int leastInterval(int n, int k, vector<char> &tasks) {
    unordered_map<char,int>mp;
    for(auto it:tasks) mp[it]++;
    priority_queue <int> pq;
    for(auto it:mp) pq.push(it.second);
    int res=0;
    while(!pq.empty()){
        int time=0;
        vector<int> v;
        for(int i=0;i<k+1;i++){
            if(!pq.empty())
            {   
                v.push_back(pq.top()-1);
                pq.pop();
                time++;
            }
        }
        for(auto t:v) if(t) pq.push(t);
        res+=pq.empty()?time:k+1;
    }
    return res;
}

//-------------using math-----------
int leastInterval(int n, int k, vector<char> &t) {
    // code here
    int mx=0,mx_cnt=0;
    unordered_map<char,int>m;
    for(auto c : t){
        m[c]++;
        mx=max(mx,m[c]);
    }
    for(auto it: m){
        if(it.second==mx)mx_cnt++;
    }
    int val=mx_cnt+(mx-1)*(k+1);
    return max(val,n);
}