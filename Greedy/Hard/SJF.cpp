#include <bits/stdc++.h>
using namespace std;

float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime) {
    float ans = 0;
    vector<vector<int> > v;
    for(int i = 0;i<n;i++){
      v.push_back({arrivalTime[i], burstTime[i]});
    }
    sort(v.begin(),v.end());
    int wait = 0,curr = 0, i = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
    while(i < n){
        if(pq.empty()){
            curr = max(v[i][0],curr);
            pq.push({v[i][1],v[i][0]});
            i++;
        }
        else if(curr >= v[i][0]){
            pq.push({v[i][1],v[i][0]});
            i++;
        }
        else {
            auto job = pq.top();
            pq.pop();
            wait += (curr - job.second);
            curr = curr + job.first;
        }
    }   
    while(!pq.empty()){
        auto job = pq.top();
        pq.pop();
        wait += (curr - job.second);
        curr = curr + job.first;
    }
    ans = (1.0)*wait/n;
    return ans;
}