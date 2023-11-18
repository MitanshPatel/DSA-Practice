// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 

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

//TOP VIEW
vector<int> topView(Node *root)
{
    vector<int> ans;
    if( root ==NULL) return ans;
    
    map<int ,int> mp;
    queue<pair<Node* ,int>> q;
    q.push({root ,0});
    
    while(!q.empty()){
        auto  it = q.front();
        q.pop();
        Node* node = it.first;
        int line =it.second;
        
        if(mp.find(line)==mp.end()) mp[line] = node->data;
        if(node->left !=NULL) q.push({node->left , line -1});
        if(node->right!=NULL) q.push({node->right,line+1});
        
    }
    for(auto i:mp) ans.push_back(i.second);
    
    return ans;
}

//BOTTOM VIEW
vector<int> topView(Node *root)
{
    vector<int> ans;
    if( root ==NULL) return ans;
    
    map<int ,int> mp;
    queue<pair<Node* ,int>> q;
    q.push({root ,0});
    
    while(!q.empty()){
        auto  it = q.front();
        q.pop();
        Node* node = it.first;
        int line =it.second;
        
        mp[line] = node->data;
        if(node->left !=NULL) q.push({node->left , line -1});
        if(node->right!=NULL) q.push({node->right,line+1});
        
    }
    for(auto i:mp) ans.push_back(i.second);
    
    return ans;
}