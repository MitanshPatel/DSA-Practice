// Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
// Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.


#include <bits/stdc++.h>
using namespace std;

//----------------For cyclic arr-------------
// Input:
// N = 3
// arr[ ] = {1, 2, 1}
// Output: {2, -1, 2}
// Explanation: The first 1's next greater number is 2:
// The number 2 can't find next greater number.
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:

// Input:
// N = 5
// arr[ ] = {5, 4, 3, 2, 1}
// Output: {-1, 5, 5, 5, 5}

vector<int> nextGreaterElement(int n, vector<int>& arr) {
    // code here
    stack<int> st;
    vector<int> ans;
    for(int j=2*n-1; j>=0; j--){
        int i=(j%n);
        if(st.size()==0){
            st.push(arr[i]);
            if(j<n)ans.push_back(-1);
        }
        else if(st.top()>arr[i]){
            if(j<n)ans.push_back(st.top());
            st.push(arr[i]);
        }
        else{
            while(st.size()!=0 && st.top()<=arr[i]){
                st.pop();
            }
            if(st.size()!=0){
                if(j<n)ans.push_back(st.top());
            }
            else{
                if(j<n)ans.push_back(-1);
            }
            st.push(arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


//----------------FOR normal Array--------------------

// Example 1:

// Input: 
// N = 4, arr[] = [1 3 2 4]
// Output:
// 3 4 4 -1
// Explanation:
// In the array, the next larger element 
// to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
// since it doesn't exist, it is -1.

vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    stack<long long> st;
    vector<long long> ans;
    for(int i=n-1; i>=0; i--){
        if(st.size()==0){
            st.push(arr[i]);
            ans.push_back(-1);
        }
        else if(st.top()>arr[i]){
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        else{
            while(st.size()!=0 && st.top()<=arr[i]){
                st.pop();
            }
            if(st.size()!=0){
                ans.push_back(st.top());
            }
            else{
                ans.push_back(-1);
            }
            st.push(arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}