// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder
// is the inorder traversal of the same tree, construct and return the binary tree.

// inorder[] = {3 1 4 0 5 2}
// preorder[] = {0 1 3 4 2 5}
// Output:
//        0
//     /     \
//    1       2
//  /   \    /
// 3    4   5

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

int findposition(int in[],int element,int start,int end){
    for(int i=start;i<=end;i++){
        if(in[i]==element)
        return i;
    }
    return -1;
}
Node* solve(int in[],int pre[],int &index,int inorderstart,int inorderend,int n){
    if(index>=n||inorderstart >inorderend){
        return NULL;
    }
    
    int element = pre[index++];
    Node* root = new Node(element);
    int position = findposition(in,element,inorderstart,inorderend);
    
    root->left=solve(in,pre,index,inorderstart,position-1,n);
    root->right=solve(in,pre,index,position+1,inorderend,n);
    
    return root;
}
Node* buildTree(int in[],int pre[], int n){
    // Code here
    int preorderindex=0;
    Node* ans = solve(in,pre,preorderindex,0,n-1,n);
    return ans;
}
