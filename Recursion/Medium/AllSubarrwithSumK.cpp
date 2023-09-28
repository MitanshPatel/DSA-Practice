// Given an array arr[] of non-negative integers and an integer sum, count all subsets of the given array with a sum equal to a given sum.

// Example 1:

// Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
//        sum = 10
// Output: 3
// Explanation: {2, 3, 5}, {2, 8}, {10} are 
// possible subsets.

#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int sum, int &cnt, int idx, int n, int currsum){
    if(idx==n){
        if(sum==currsum){
            cnt=(cnt+1);
            return;
        }
        else return;
    }
    if(currsum<=sum) solve(arr, sum, cnt, idx+1, n, currsum);
    currsum += arr[idx];
    if(currsum<=sum) solve(arr, sum, cnt, idx+1, n, currsum);
    return;
}

int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    int cnt=0;
    int idx=0;
    int currsum=0;
    solve(arr, sum, cnt, idx, n, currsum);
    return cnt;
}