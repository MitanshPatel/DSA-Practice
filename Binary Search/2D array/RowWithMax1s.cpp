// You have been given a non-empty grid ‘mat’ with ‘n’ rows and ‘m’ columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
// Your task is to find the index of the row with the maximum number of ones.
// Note: If two rows have the same number of ones, consider the one with a smaller index. If there’s no row with at least 1 zero, return -1.

#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    // code here
    int low=0, high=m-1;
    int ans=-1;
    int pres=false; //if true -> 1 is present
    while(low<=high){
        int mid=(low+high)/2;
        for(int i=0; i<n; i++){
            if(arr[i][mid]==1){ //if 1 got encountered in mid col
                ans=i;
                pres=true;
                break;
            }
        }
        if(pres) high=mid-1;
        else low=mid+1;
        pres=false;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix, n, m) << '\n';
}