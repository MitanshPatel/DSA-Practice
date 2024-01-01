// Geek is going for n days training program, he can perform any one of these three activities Running, Fighting, and Learning Practice. Each activity has some point on each day. as Geek wants to improve all his skills, he can't do the same activity on two consecutive days, help Geek to maximize his merit points as we were given a 2D array of n*3 points corresponding to each day and activity.

// Example:
// Input:
// n = 3
// point= [[1,2,5],[3,1,1],[3,3,3]]
// Output:
// 11
// Explanation:
// Geek will learn a new move and earn 5 point then on second
// day he will do running and earn 3 point and on third day
// he will do fighting and earn 3 points so, maximum point is 11.

#include <bits/stdc++.h>
using namespace std;

//--------------Memoization--------------
int helper(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
    
    if(dp[day][last] != -1) return dp[day][last];
    
    if(day == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }
    
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i != last){
            int activity = points[day][i] + helper(day-1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }
    return dp[day][last] = maxi;
}

//-------------Tabulation----------------
int maximumPoints(vector<vector<int>>& points, int n) {
    vector<vector<int>> dp(n, vector<int> (4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last] = 0;
            for(int task=0;task<=2;task++){
                if(task != last){
                    int activity = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }
    return dp[n-1][3];
}