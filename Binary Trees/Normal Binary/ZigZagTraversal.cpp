// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

// Example 1:
// Input:
//         1
//       /   \
//      2     3
//     / \   /  \
//    4   5 6    7
// Output:
// 1 3 2 4 5 6 7

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector <int> zigZagTraversal(Node* root){   
    vector<int> v;
    if(root == NULL) return v;
    
    queue<Node*> q;
    q.push(root);
    bool leftToright = true;
    
    while(!q.empty()) {
        int size = q.size();
        vector<int> t(size);
        
        for(int i=0; i<size; i++) {
            Node* temp = q.front();
            q.pop();
            
            int index = leftToright? i : size - 1 - i;
            t[index] = temp->data;
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
        }
        
        for(auto i:t){
            v.push_back(i);
        }
        
        leftToright =! leftToright;
    }
    return v;
    
}