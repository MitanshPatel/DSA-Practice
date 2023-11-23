// Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively.
// The task is to construct the binary tree from these traversals.

// Example 1:
// Input:
// N = 8
// in[] = 4 8 2 5 1 6 3 7
// post[] =8 4 5 2 6 7 3 1
// Output:
//            1
//        /      \
//      2         3
//    /  \      /  \
//   4    5    6    7
//    \
//      8


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

int postInd;
map<int,int>m;
Node* build(int post[],int s,int e){
    if(s>e)return NULL;
    Node* root=new Node(post[postInd--]);
    int inInd=m[root->data];
    root->right=build(post,inInd+1,e);
    root->left=build(post,s,inInd-1);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    postInd=n-1;
    for(int i=0;i<n;i++) m[in[i]]=i;
    return build(post,0,n-1);
}