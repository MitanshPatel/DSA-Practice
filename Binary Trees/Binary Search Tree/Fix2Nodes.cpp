// You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
// Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.
 
// Example 1:
// Input:
//        10
//      /    \
//     5      8
//    / \
//   2   20
// Ans: swap 8 and 20

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

Node* first, *second, *previ; 
void traverse(Node* root){
    if(!root)return;
    traverse(root->left);
    if(previ && (root->data < previ->data)){
        if(!first){
            first = previ; second = root;
        }
        else second = root;
    }
    previ = root;
    traverse(root->right);
}
void correctBST( struct Node* root )
{
    // add code here.
    first=NULL, second=NULL, previ=NULL;
    traverse(root);
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}