//RIGHT
// Input:
//      10
//     /   \
//   20     30
//  /   \
// 40  60 
// Output: 10 30 60

//LEFT
// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
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

//LEFT ITERATIVE
vector<int> leftView(Node *root){
   // Your code here
   vector<int> ans;
   if(root==NULL)  return ans;
   queue<Node*> q;
   q.push(root);
   while(q.size()){
       int a  = q.size();
      for(int i=0;i<a;i++){
           Node* curr = q.front();
           q.pop();
           if(i==0)  ans.push_back(curr->data);
           if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
           
       }
   }
   return ans;
}
//LEFT RECURSIVE
void solve(Node* root, vector<int> &ans, int level) {
   // base case
   if(root == NULL)
       return ;
   
   // we entered in new level if below condition is true
   if(level == ans.size())
       ans.push_back(root -> data);
   
   solve(root -> left, ans, level + 1);
   solve(root -> right, ans, level + 1);
}
vector<int> leftView1(Node *root)
{
  vector<int> ans;
  solve(root, ans, 0);
  return ans;
}

//RIGHT ITERATIVE
vector<int> rightView(Node *root){
    vector<int> ans;
    if(!root)   return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        int counter = 0;
        for(int i=0; i<size; i++){
            Node *temp = q.front();
            q.pop();
            
            if(i==size-1)ans.push_back(temp->data);
            
            if(temp->left)  
                q.push(temp->left);
            if(temp->right) 
                q.push(temp->right);
            
        }
        
    }
    return ans;
}
//RIGHT RECURSIVE
void solve(Node* root, vector<int> &ans, int level){
    if(root==NULL)
        return ;
    if(level == ans.size()) {
        ans.push_back(root->data);
    }   
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
}
vector<int> rightView(Node *root){
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}