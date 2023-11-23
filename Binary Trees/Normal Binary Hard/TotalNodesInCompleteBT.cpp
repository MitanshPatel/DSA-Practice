// You are given the root of a complete binary tree. Your task is to find the count of nodes.
// A complete binary tree is a binary tree whose, all levels except the last one are completely filled,
// the last level may or may not be completely filled and Nodes in the last level are as left as possible.
// Design an algorithm that runs better than O(n).

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

int findHeightLeft(Node* root){
    int hgt = 0;
    while(root){
        hgt++;
        root = root->left;
    }
    return hgt;
}
int findHeightRight(Node* root){
    int hgt = 0;
    while(root){
        hgt++;
        root = root->right;
    }
    return hgt;
}
int countNodes(Node* root) {
    // Write your code here
    if(root==NULL) return 0;
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    
    if(lh == rh) return (1<<lh) - 1;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}