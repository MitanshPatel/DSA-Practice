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

bool sym(struct Node* root1,struct Node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL && root2!=NULL || root1!=NULL && root2==NULL)
        return false;
        
    if(root1->data!=root2->data)
        return false;
    return (sym(root1->left,root2->right)  && sym(root1->right,root2->left));
}

bool isSymmetric(struct Node* root){
// Code here
    if(root==NULL)
        return true;
    return sym(root->left,root->right);
}