// Given a binary tree, find if it is height balanced or not. 
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

// A height balanced tree
//         1
//      /     \
//    10      39
//   /
// 5

// An unbalanced tree
//         1
//      /    
//    10   
//   /
// 5

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

int height(Node* r,bool &flag){
    if(!r || !flag) return 0;
    int lh=height(r->left,flag);
    int rh=height(r->right,flag);
    if(abs(lh-rh)>1) flag=0;
    return max(lh,rh)+1;
}
bool isBalanced(Node *root)
{
    bool flag=1;
    height(root,flag);
    return flag;
}