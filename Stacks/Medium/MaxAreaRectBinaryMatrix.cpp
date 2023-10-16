// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

// Example 1:
// Input:
// n = 4, m = 4
// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8

// the max size rectangle is 
// 1 1 1 1
// 1 1 1 1
// and area is 4 *2 = 8.


#include <bits/stdc++.h>
using namespace std;

void nslnsr(vector<int>&arr , vector<int>&heights , int n , string s){
    stack<int>st;
    if(s == "nsl"){
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                arr[i] = st.top();
            }
            st.push(i);
        }
    }
    else{
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                arr[i] = st.top();
            }
            st.push(i);
        }
    }
}

int max_area_of_hist(vector<int>&arr , int size){
    vector<int>left(size,-1);
    vector<int>right(size,size);
    nslnsr(left , arr , size , "nsl");
    nslnsr(right , arr , size , "nsr");
    int ans = arr[0];
    for(int i=0;i<size;i++){
        ans = max(ans , (right[i] - left[i] - 1)*arr[i]);
    }
    return ans;
}

int maxArea(int **matrix, int n, int m){
    int maxarea = 0;
    vector<int>update(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                update[j] = 0;
            }
            else{
                update[j] += matrix[i][j];
            }
        }
        maxarea = max(maxarea , max_area_of_hist(update , m));
    }
    return maxarea;
}