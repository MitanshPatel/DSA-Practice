// Given two integer array A and B of size N each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum K valid sum combinations from all the possible sum combinations.

// Note : Output array must be sorted in non-increasing order.

// Example 1:
// Input:
// N = 4
// K = 3
// A [ ] = {1, 4, 2, 3}
// B [ ] = {2, 5, 1, 6}
// Output: {10, 9, 9}
// Explanation: 
// 10 -> (A : 4) + (B : 6)
// 9 -> (A : 4) + (B : 5)
// 9 -> (A : 3) + (B : 6)

#include <bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
    // code here
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pair<int,pair<int,int>>> maxheap;
    set<pair<int,int>> s;
    s.insert({N-1,N-1});
    maxheap.push({A[N-1]+B[N-1],{N-1,N-1}});
    vector<int> ans;
    while(K--){
        auto it=maxheap.top();
        maxheap.pop();
        int sum = it.first;
        int i=it.second.first;
        int j=it.second.second;
        ans.push_back(sum);
        if(i-1>=0 and s.find({i-1,j})==s.end()){
            maxheap.push({A[i-1]+B[j],{i-1,j}});
            s.insert({i-1,j});
        }
        if(j-1>=0 and s.find({i,j-1})==s.end()){
            maxheap.push({A[i]+B[j-1],{i,j-1}});
            s.insert({i,j-1});
        }
    }
    return ans;
}