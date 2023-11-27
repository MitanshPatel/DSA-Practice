// Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum. 

// Example 1:

// Input:
//         2
//       /   \
//      1     3
// sum = 5
// Output: 1 
// Explanation: 
// Nodes with value 2 and 3 sum up to 5.

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

void left(Node* root, stack<Node*> &s){
    while(root){
        s.push(root);
        root=root->left;
    }
}
void right(Node* root, stack<Node*> &s){
    while(root){
        s.push(root);
        root=root->right;
    }
}
int isPairPresent(struct Node *root, int target)
{
//add code here.
    stack<Node*> s1,s2;
    left(root,s1);
    right(root,s2);
    while(!s1.empty() && !s2.empty()){
        Node* a = s1.top();
        Node* b = s2.top();
        
        if(a->data + b->data < target){
            s1.pop();
            left(a->right,s1);
        }else if(a->data + b->data > target){
            s2.pop();
            right(b->left,s2);
        }else{
            return 1;
        }
    }
    return 0;
}