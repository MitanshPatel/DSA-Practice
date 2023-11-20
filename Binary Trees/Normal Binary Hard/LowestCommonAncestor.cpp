// Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

// LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

// Example 1:

// Input:

// Input:
// n1 = 9 , n2 = 4
//            5    
//           / \   
//          2   6
//         / \   \
//        3   4   8
//         \
//          9 
// Output: 2
// Explanation:
// LCA of 9 and 4 is 2. 

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

//OPTIMAL
Node* lca(Node* root ,int n1 ,int n2 ){
       if(root == NULL) {
           return NULL;
       }
       if(root->data == n1 || root->data == n2) {
           return root;
       }
       Node *left = lca(root->left, n1, n2);
       Node *right = lca(root->right, n1, n2);
       if(left != NULL && right != NULL) {
           return root;
       }
       if(left != NULL) {
           return left;
       }
       else {
           return right;
       }
}

//BRUTE
bool getPath(Node* root ,int x ,vector<Node*> &path) {
    if(root == NULL)
        return false;
        
    path.push_back(root);
    
    if(root->data == x)
        return true;
    
    if(getPath(root->left, x, path) ||
        getPath(root->right, x, path))
        return true;
    
    path.pop_back();
    return false;
}

Node* lca(Node* root ,int n1 ,int n2 )
{
    //Your code here 
    if(root == NULL)
    return NULL;
    
    vector<Node* > path1;
    vector<Node* > path2;
    getPath(root, n1, path1);
    getPath(root, n2, path2);
    root = NULL;
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++)
    {
        if(path1[i] == path2[j])
            root = path1[i];
        else
            return root;
    }
    
    return root;
}