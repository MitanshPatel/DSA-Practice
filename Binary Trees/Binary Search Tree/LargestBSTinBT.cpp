// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

// Example 1:

// Input:
//         1
//       /   \
//      4     4
//    /   \
//   6     8
// Output: 1
// Explanation: There's no sub-tree with size
// greater than 1 which forms a BST. All the
// leaf Nodes are the BSTs with size equal
// to 1.

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

vector<int> solve(Node* root)
{
    if(root == NULL) // agr yeh NULL hai
    return { 0, INT_MAX, INT_MIN};
    
    vector<int> left = solve(root -> left); // come from left side
    vector<int> right = solve(root -> right); // come from right side
    
    // khd BST ki condition
    if(root -> data > left[2] && root -> data < right[1]){
        int x = left[1];  //min of left tree
        int y = right[2];  //max of right tree
        
        // return (see  above)
        return {left[0] + right[0] + 1, min(x, root->data), max(y,root->data) };
    }
    
    return {max(left[0], right[0]), INT_MIN,INT_MAX};
}
int largestBst(Node *root)
{
    //Your code here
    
    /*
    solve teen values return krega
    1) size of BST
    2) abhi tk min value kya mili hai hme
    3) abhi tk max value kya mili hai hme 
    */
    vector<int> ans = solve(root);
    return ans[0];
}