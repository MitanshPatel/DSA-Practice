// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

// Example 1:

// Input:
//         1 
//       /   \
//      2     3  
//     / \   / \ 
//    4   5 6   7
//       / \
//      8   9
   
// Output: 1 2 4 8 9 6 7 3

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};


void traverseLeft(Node* root,vector<int>& ans){
    
    // Base Case
    if((root==NULL) || (root->left == NULL && root->right == NULL)) return;
    ans.push_back(root->data);
    
    if(root->left) traverseLeft(root->left,ans);
    else traverseLeft(root->right,ans);
    
}

void traverseLeaf(Node* root,vector<int>& ans){
    
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    
}

void traverseRight(Node* root,vector<int>& ans){
    
    if((root==NULL) || (root->left == NULL && root->right == NULL)) return;
    if(root->right) traverseRight(root->right,ans);
    else traverseRight(root->left,ans);
    
    // Reverse order mai store karlo
    ans.push_back(root->data);
    
}

vector <int> boundary(Node *root)
{
    vector<int>ans;
    if(root == NULL) return ans;
    ans.push_back(root->data);
    
    // Step1 : Traverse Left Part
    traverseLeft(root->left,ans);
    
    // Step2: Traverse Leaf Nodes
    traverseLeaf(root->left,ans); // Left Subtree
    traverseLeaf(root->right,ans); // Right Subtree
    
    // Step3: Traverse Right Part
    traverseRight(root->right,ans);
    
    return ans; 
}