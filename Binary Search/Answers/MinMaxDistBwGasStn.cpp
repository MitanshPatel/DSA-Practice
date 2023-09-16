// You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. 
//You are also given an integer ‘k’. You have to place ‘k’ new gas stations on the X-axis.
// You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. 
//Let ‘dist’ be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
// Find the minimum value of ‘dist’.

// Note: Answers within 10^-6 of the actual answer will be accepted. For example, if the actual answer is 0.65421678124, 
//it is okay to return 0.654216. Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place.

// Examples
// Example 1:
// Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
// Result: 0.5
// Explanation: One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this. 
// Example 2:
// Input Format: N = 10, arr[] = {1,2,3,4,5,6,7,8,9,10}, k = 1
// Result: 1
// Explanation: One of the possible ways to place 1 gas station is {1,1.5,2,3,4,5,6,7,8,9,10}. Thus the maximum difference between adjacent gas stations is still 1. Hence, the value of ‘dist’ is 1. It can be shown that there is no possible way to add 1 gas station in such a way that the value of ‘dist’ is lower than this.




#include <bits/stdc++.h>
using namespace std;
//using bs
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

//using heap priority queue
long double minimiseMaxDistance2(vector<int> &arr, int k) {
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    //insert the first n-1 elements into pq
    //with respective distance values:
    for (int i = 0; i < n - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;

        //insert the current gas station:
        howMany[secInd]++;

        long double inidiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = inidiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
