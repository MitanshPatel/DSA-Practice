// Given a Binary Tree of size N, you need to find all the possible paths from root node to all the leaf node's of the binary tree.

// Example 1:
// Input:
//          10
//        /    \
//       20    30
//      /  \
//     40   60
// Output: 10 20 40 #10 20 60 #10 30 #

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


void solve(Node* root,vector<int> &ans,vector<vector<int>> &v){
    if(!root) return;
    ans.push_back(root->data);
    if(root->left) solve(root->left,ans,v);
    if(root->right) solve(root->right,ans,v);
    if(!root->left and !root->right){
        v.push_back(ans);
    }
    ans.pop_back();
}

vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> v;
    vector<int> ans;
    solve(root,ans,v);
    return v;
}