// Geek has an array of N non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti.
// He wants to add a new interval newEvent = [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.
// Help Geek to insert newEvent into intervals such that intervals is still sorted in ascending order by starti and 
// intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Example 1

// Input:
// N = 5
// intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
// newEvent  = [5,10]
// Output: [[1,2], [3,10], [12,16]]
// Explanation: Because the new interval [5,10] overlaps with [3,5],[6,7],[8,10].

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
    vector<vector<int>> ans;
    int i = 0;
    while(i < N && newEvent[0] > intervals[i][1]){
        ans.push_back(intervals[i]);
        i++;
    }
    while(i < N && newEvent[1] >= intervals[i][0]){
        newEvent[0] = min(intervals[i][0],newEvent[0]);
        newEvent[1] = max(intervals[i][1],newEvent[1]);
        i++;
    }
    ans.push_back(newEvent);
    while(i<N){
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}