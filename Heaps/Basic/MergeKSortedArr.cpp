// Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

// Example 1:
// Input:
// K = 4
// arr[][]={{1,2,3,4},{2,2,3,4},
//          {5,5,6,6},{7,8,9,9}}
// Output:
// 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
// Explanation: Above test case has 4 sorted
// arrays of size 4, 4, 4, 4
// arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
// [5, 5, 6, 6], [7, 8, 9, 9 ]]
// The merged list will be 
// [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
// 6, 6, 7, 8, 9, 9].

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>>triplet;
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<triplet,vector<triplet>,greater<triplet>>pq;
    for(int i=0;i<K;i++){
        pq.push({arr[i][0],{i,0}});
    }
    vector<int>res;
    while(!pq.empty()){
        triplet curr=pq.top();
        pq.pop();
        res.push_back(curr.first);
        int ap=curr.second.first;
        int vp=curr.second.second;
        if(vp+1< arr[ap].size()){
            pq.push({arr[ap][vp+1],{ap,vp+1}});
        }
    }
    return res;
}