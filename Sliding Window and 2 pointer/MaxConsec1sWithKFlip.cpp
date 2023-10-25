// You are given array nums of n length and an integer k .return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example:

// Input:
// n = 11
// nums = [1,1,1,0,0,0,1,1,1,1,0]
// k = 2
// Output:
// 6
// Explanation:
// You can flip 2 0 and obtain  [1,1,1,0,0,1,1,1,1,1,1]

#include<bits/stdc++.h>
using namespace std;

int longestOnes(int n, vector<int>& nums, int k) {
    // Code here
    int i = 0;
    int j = 0;
    int cnt0=0;
    int maxi = 0;
    while(j<n) {
        if(nums[j]==1) {
            j++;
        } else {
            if(cnt0<k) {
                cnt0++;
                j++;
            } else {
                while(nums[i]!=0) {
                    i++;
                }
                i++;
                cnt0--;
            }
        }
        maxi = max(maxi, j-i);
    }
    return maxi;
}