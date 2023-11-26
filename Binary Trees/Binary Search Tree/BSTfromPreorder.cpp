//Given an array arr[] of N nodes representing preorder traversal of some BST. create the BST

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
Node* newNode( int data ){
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int i = 0;
Node* build(int pre[] , int n , int mxval){
    if(i == n || pre[i] > mxval){
        return NULL;
    }
    
    Node* root = newNode(pre[i++]);
    
    root->left = build(pre , n , root->data);
    root->right = build(pre , n , mxval);
    return root;
}
Node* post_order(int pre[], int size){
    i = 0;
    return build(pre , size , INT_MAX);
}