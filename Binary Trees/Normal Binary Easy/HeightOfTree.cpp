// Given a binary tree, find its height.

// Example 1:

// Input:
//      1
//     /  \
//    2    3
// Output: 2

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

//Recursive
int height(struct Node* root){
    if(root == NULL) return 0;
        
    return 1 + max(height(root->left), height(root->right));
}

//Iterative Level Order
int levelordertraversal(struct Node*root){
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
   int height = 0;
   while (!q.empty()){
       Node*temp = q.front();
       q.pop();
       if (temp == NULL){
          height++;
           if (!q.empty()){
               q.push(NULL);
           }
       }
       else{
           if (temp->left){
               q.push(temp->left);
           }
           if (temp->right){
               q.push(temp->right);
           }
       }
   }
   return height;
}

//Function to find the height of a binary tree.
int height(struct Node* node){
return levelordertraversal(node);
}