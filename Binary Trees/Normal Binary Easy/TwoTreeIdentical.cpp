// Given two binary trees, the task is to find if both of them are identical or not.
// Note: You need to return true or false, the printing is done by the driver code.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

bool isIdentical(Node *r1, Node *r2){
    
    if((r1==NULL && r2==NULL) || (r1==r2 && r1->data == r2->data)){
        return true;
    }

    if((r1 && !r2) || (!r1 && r2) || (r1->data!=r2->data)){
        return false;
    }
    
    return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
}