// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

// postTweet (userId, tweetId): Compose a new tweet.
// getNewsFeed (userId): Retrieve the 10 most recent tweet ids in the user's news feed (If total number of tweets in news feed is less than 10, then return all). Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
// follow (followerId, followeeId): Follower follows a followee.
// unfollow (followerId, followeeId): Follower unfollows a followee.
// Example 1:

// Input:
// postTweet(1, 5);
// getNewsFeed(1);
// follow(1, 2);
// postTweet(2, 6);
// getNewsFeed(1);
// unfollow(1, 2);
// getNewsFeed(1);

// Output:
// [5]
// [6, 5]
// [5]

// Explanation: 
// postTweet(1,5): User 1 posts a new tweet (id=5)
// getNewsFeed(1): Return a list with 1 tweet [5]
// follow(1,2)   : User 1 follows user 2.
// postTweet(2,6): User 2 posts a new tweet (id=6)
// getNewsFeed(1): Return a list with 2 tweets 
// [6,5]. One his own tweet and one followee's tweet
// (sorted from most recent to least recent).
// unfollow(1,2) : User 1 unfollows user 2
// getNewsFeed(1): Return a list with 1 tweet [5],
// because user 1 is no longer following anyone.

#include <bits/stdc++.h>
using namespace std;

class Twitter {
    long long time;
    unordered_map<int,set<int>>following;   // <user, all the users it followes>
    unordered_map<int,vector<pair<int,int>>>tweets;  // <user, all his tweets <time, tweetContent>>
  public:
    // Initialize your data structure here
    Twitter() {
        time=0;
    }

    // Compose a new tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }

    // Retrieve the 10 most recent tweet ids as mentioned in question
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        //tweets of the user itself
        for(auto it:tweets[userId]) pq.push(it);
        
        //tweets of its followers
        for(int follower:following[userId]){
            for(auto it:tweets[follower]) pq.push(it);
        }
        
        //only first 10 tweets
        while(!pq.empty() && res.size()<10){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    // Follower follows a followee. If the operation is invalid, it should be a
    // no-op.
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    // Follower unfollows a followee. If the operation is invalid, it should be
    // a no-op.
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};