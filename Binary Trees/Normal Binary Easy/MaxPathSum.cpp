// Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

// Example 1:

// Input:
//      10
//     /  \
//    2   -25
//   / \  /  \
//  20 1  3  4
// Output: 32
// Explanation: Path in the given tree goes
// like 10 , 2 , 20 which gives the max
// sum as 32.

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

int findPath(Node *root, int &maxSum) {
    if(!root) return 0;
    int leftSum = max(0, findPath(root->left, maxSum));
    int rightSum = max(0, findPath(root->right, maxSum));
    maxSum = max(maxSum, leftSum + root->data + rightSum);
    return root->data + max(leftSum, rightSum);
}

int findMaxSum(Node* root){
    int maxSum = INT_MIN;
    findPath(root, maxSum);
    return maxSum;
}