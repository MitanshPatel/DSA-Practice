// Given an array of N integers arr[] where each element represents the maximum length of the jump that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.

// Example 1:
// Input:
// N = 11 
// arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
// Output: 3 
// Explanation: 
// First jump from 1st element to 2nd element with value 3. Now, from here 
// we jump to 5th element with value 9, and from here we will jump to the last. 

#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
    
    // agar pahale hi point pr zero pada ho to bhaiya kaha jaoge. Ruk jao
    if(arr[0] == 0 && n>1) return -1;
    
    if(n == 1) return 0;
    
    // assume kro ki pahale point se apan jump lga diye hai
    int steps = arr[0];
    int maxReach = arr[0];
    int jumps = 1;
    
    for(int i = 1; i<n; i++){
        
        if(i == n-1) return jumps;
        
        // Ab apan agle point par aagye to maxReach nikalo aur store kralo
        if(steps) {
            maxReach = max(maxReach, arr[i]+i);
        
            // Ab apan agle point pr aagye hai to ek 			 step kam kardo
            steps--;
        }
        
        // check kro ki steps khatm to nhi ho gye
        if(steps == 0){
            
            // agar end point tak pahuchne se pahale koi zero mil gya aur usse pahale koi maxReach nhi tha
            if(i>=maxReach) return -1;
            
            // steps khatm hue matlab new point par aagye
            // yha se bhi jump lga do
            // apan jump tabhi lagayenge jab steps khatm ho jayenge
            jumps++;
            
            // steps ko update krlo
            steps = maxReach - i;
        }
    }
    return -1;
}