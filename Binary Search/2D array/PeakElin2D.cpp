// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.


#include <bits/stdc++.h>
using namespace std;
vector<int> findPeakGrid(vector<vector<int>> &g)
{
    int n = g.size(), m = g[0].size();
    int l = 0, r = n - 1;

    // Function to find the index of maximum element in current row.
    const auto findMax = [&](vector<int> &row) -> int
    {
        int index = 0;
        for (int i = 0; i < m; i++)
        {
            if (row[i] > row[index])
                index = i;
        }
        return index;
    };

    // Binary searching on the row with a peak element,
    // if the maximum element of the current row is at index 'ind'
    // and g[mid][ind]>g[mid+1][ind] then we can find a peak element
    // in rows [l,mid].
    while (l < r)
    {
        int mid = (l + r) / 2;
        int ind = findMax(g[mid]);
        if (mid == n - 1 || g[mid][ind] > g[mid + 1][ind])
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return {l, findMax(g[l])};
}