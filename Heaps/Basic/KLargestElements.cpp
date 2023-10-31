// Given an array of N positive integers, print k largest elements from the array. 

// Example 1:
// Input:
// N = 5, k = 2
// arr[] = {12,5,787,1,23}
// Output: 787 23
// Explanation: First largest element in
// the array is 787 and the second largest
// is 23.

#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k){
    // code here
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k; i++){
        q.push(arr[i]);
    }
    for (int i = k; i < n; i++){
        if (q.top() <= arr[i]){
            q.pop();
            q.push(arr[i]);
        }
    }
    while (q.size()){
        ans.push_back(q.top());
        q.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}