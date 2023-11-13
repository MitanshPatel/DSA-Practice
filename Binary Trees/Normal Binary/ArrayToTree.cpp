// Input: 
// nodes = [1 2 3 4 5 6 7]
// Output: 
//          1
//        /   \
//      2       3
//    /  \     /  \
//    4  5    6   7
// Explanation: 
// The 7 node binary tree is represented above.

#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

void create_tree(node* root0, vector<int> &vec){
    //Your code goes here
    queue<node*>q;
    q.push(root0);
    
    int i = 1;
    int n = vec.size();
    
    while(i < n){
        node * root = q.front();
        q.pop();
        
        node * left = newNode(vec[i]);
        root->left = left;
        i++;
        q.push(left);
        
        
        node * right = newNode(vec[i]);
        root->right = right;
        i++;
        q.push(right);
    }
}