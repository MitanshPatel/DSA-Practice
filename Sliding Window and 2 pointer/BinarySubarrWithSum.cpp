// Given a binary array arr of size N and an integer target, return the number of non-empty subarrays with a sum equal to target.

// Example 1:
// Input:
// N = 5
// target = 2
// arr[ ] = {1, 0, 1, 0, 1}
// Output: 4
// Explanation: The 4 subarrays are:
// {1, 0, 1, _, _}
// {1, 0, 1, 0, _}
// {_, 0, 1, 0, 1}
// {_, _, 1, 0, 1}
 
#include<bits/stdc++.h>
using namespace std;


int atmost(vector<int>& arr,int k)
{
    int start = 0;
    int end = 0;
    int count = 0;
    int sum = 0;

    while (end < arr.size()) {
        sum += arr[end];

        while (sum > k) {
            sum -= arr[start];
            start++;
        }
        count += (end - start + 1);
        end++;
    }

    return count;
}
int numberOfSubarrays(vector<int>& arr, int N, int target)
{
    return atmost(arr,target) - atmost(arr,target-1);
}