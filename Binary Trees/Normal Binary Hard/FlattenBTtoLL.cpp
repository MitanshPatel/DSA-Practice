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

//recursive
Node* previ = NULL;
void flatten(Node *root)
{
    //code here
    if (!root) return;
    
    flatten(root->right);
    flatten(root->left);
    
    root->left = NULL;
    root->right = previ;
    previ = root;
}

void flatten(Node * root) {
  if (root == NULL) return;
  stack < Node * > st;
  st.push(root);
  while (!st.empty()) {
    Node * cur = st.top();
    st.pop();

    if (cur -> right != NULL) {
      st.push(cur -> right);
    }
    if (cur -> left != NULL) {
      st.push(cur -> left);
    }
    if (!st.empty()) {
      cur -> right = st.top();
    }
    cur -> left = NULL;
  }