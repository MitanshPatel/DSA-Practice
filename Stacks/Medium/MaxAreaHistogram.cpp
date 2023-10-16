// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. 
// assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

// Example 1:

// Input:
// N = 7
// arr[] = {6,2,5,4,5,1,6}
// Output: 12
// Explanation: In this example the largest area would be 12 of height 4 and width 3. We can achieve this 
// area by choosing 3rd, 4th and 5th bars.

#include <bits/stdc++.h>
using namespace std;

vector<int> nsl(long long arr[], int n)  //next smallest element at left
{
    vector<int> v;
    stack<pair<long long, int>> st;
    
    for(int i=0;i<n;i++)
    {
        while(!st.empty() and st.top().first>=arr[i])
        st.pop();
        
        st.empty()? v.push_back(-1): v.push_back(st.top().second);
        st.push({arr[i],i});
    }
    return v;
}


vector<int> nsr(long long arr[], int n)
{
    vector<int> v;
    stack<pair<long long, int>> st;
    
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() and st.top().first>=arr[i])
        st.pop();
        
        st.empty()? v.push_back(n): v.push_back(st.top().second);
        st.push({arr[i],i});
    }
    reverse(v.begin(),v.end());
    return v;
}


long long getMaxArea(long long arr[], int n)
{
    vector<int> left=nsl(arr,n);
    vector<int> right=nsr(arr,n);
    long long ans=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        ans=max(ans,arr[i]*(right[i]-left[i]-1));
    }
    return ans;
}