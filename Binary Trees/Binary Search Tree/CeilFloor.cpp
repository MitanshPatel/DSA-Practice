//find ceil and floor of a number in BST
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

//----------FLOOR------------
int ans = -1;
int floor(Node* root, int x) {
    if(!root)
        return ans;
    
    if(root->data <= x){
        ans = root->data;  // that could be my potential ans
        return floor(root->right,x);
    }
    
    else{
        return floor(root->left,x);
    }
}

//--------CEIL----------
int findCeil(Node* root, int input) {
   int ans=-1;
   while(root){
       if(root->data>=input){
           ans=root->data;
           root=root->left;
       }
       else
        root=root->right;
   }
   return ans;
}