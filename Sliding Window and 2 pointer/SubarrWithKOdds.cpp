// You are given array nums of n elements and integer K, and count the number of subarrays that has k odd numbers.

// Input:
// n = 5
// nums = [1,1,2,1,1]
// k = 3
// Output:
// 2
// Explanation:
// There are 2 subarrays with k odds [1,1,2,1] and [1,2,1,1]

#include<bits/stdc++.h>
using namespace std;

int atmost(int n, vector<int>& nums, int k){
    int i=0,j=0;
    int count=0;
    int ans=0;
    while(j<n){
        if(nums[j]%2!=0){
            count++;
        }
        
        while(count>k){
            if(nums[i]%2!=0){
                count--;
            }
            i++;
        }
        
        ans+=j-i+1;
        j++;
    }
    return ans;
}
int countSubarray(int n, vector<int>& nums, int k) {
    int answer;
    answer=atmost(n,nums,k)-atmost(n,nums,k-1);
    return answer;
}
