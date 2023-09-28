//if there is one subarr with give sum k, then return true, else false
#include <bits/stdc++.h>
using namespace std;

bool solve(int arr[], int sum, int &cnt, int idx, int n, int currsum){
    if(idx==n){
        if(sum==currsum){
            return true;
        }
        else return false;
    }
    if(solve(arr, sum, cnt, idx+1, n, currsum) == true){
        return true;
    } 
    solve(arr, sum, cnt, idx+1, n, currsum);

    currsum += arr[idx];

    if(solve(arr, sum, cnt, idx+1, n, currsum) == true){
        return true;
    } 
    solve(arr, sum, cnt, idx+1, n, currsum);
    return;
}

int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    bool exist=false;
    int cnt=0;
    int idx=0;
    int currsum=0;
    exist = solve(arr, sum, cnt, idx, n, currsum);
    return cnt;
}