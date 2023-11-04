// Given an input stream arr[] of n integers. Find the Kth largest element (not Kth largest unique element) after insertion of each element
// in the stream and if the Kth largest element doesn't exist, the answer will be -1 for that insertion.
// return a list of size n after all insertions.

// Example 1:

// Input:
// k = 4, n = 6
// arr[] = {1, 2, 3, 4, 5, 6}
// Output:
// -1 -1 -1 1 2 3
// Explanation:
// k = 4
// For 1, the 4th largest element doesn't
// exist so answer will be -1.
// For 2, the 4th largest element doesn't
// exist so answer will be -1.
// For 3, the 4th largest element doesn't
// exist so answer will be -1.
// For 4, the 4th largest element is 1.
// For 5, the 4th largest element is 2.
// for 6, the 4th largest element is 3.

#include <bits/stdc++.h>
using namespace std;

vector<int> kthLargest(int k, int arr[], int n) {
    priority_queue<int, vector<int>, greater<int>>pq;
    int i=0;
    vector<int>v;
    while(i<n){
        pq.push(arr[i]);
        if(k>pq.size())
            v.push_back(-1);
        else if(k<pq.size()){ 
            pq.pop(); 
            v.push_back(pq.top());
        }
        else{
            v.push_back(pq.top());
        }
        i++;
    }
    return v;   
}