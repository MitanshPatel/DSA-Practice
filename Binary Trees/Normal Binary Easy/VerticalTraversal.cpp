// Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
// If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

// Example 1:

// Input:
//            1
//          /   \
//        2       3
//      /   \   /   \
//    4      5 6      7
//               \      \
//                8      9           
// Output: 
// 4 2 1 5 6 3 8 7 9 

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> verticalOrder(Node *root){
    //Your code here
    map<int,vector<int>> mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(q.size()){
        
        auto a = q.front();
        q.pop();
        Node* curr = a.first;
        int val = a.second;
        mp[val].push_back(curr->data);
        
        if(curr->left)q.push({curr->left, val-1});
        if(curr->right)q.push({curr->right, val+1});
    }
    vector<int> res;
    
    for(auto it: mp){
            vector<int> ans = it.second;
            for(auto ti : ans){
                res.push_back(ti);
            }
        
    }
    
    return res;
}