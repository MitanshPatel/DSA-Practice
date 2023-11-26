// Given a Binary Search Tree (with all values unique) and two node values n1 and n2 (n1!=n2).
// Find the Lowest Common Ancestors of the two nodes in the BST.

// Example 1:
// Input:
//               5
//             /   \
//           4      6
//          /        \
//         3          7
//                     \
//                      8
// n1 = 7, n2 = 8
// Output: 7

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

//---------Recursive----------
Node* LCA(Node *root, int n1, int n2){
    if(!root) return NULL;
    int num = root->data;
    if(num>n1 and num>n2) return LCA(root->left,n1,n2);
    if(num<n1 and num<n2) return LCA(root->right,n1,n2);
    return root;
}

//----------Iterative---------------
Node* LCA(Node *root, int n1, int n2){
    //Your code here
    Node *temp = root;
    if(!root)
        return root;
    while(temp){
        if(n1< temp->data && n2<temp->data)
            temp = temp->left;
        else if(n1>temp->data && n2>temp->data)
            temp = temp->right;
        else
            return temp;
    }
    return root;
    
}