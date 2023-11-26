// Given a BST and an integer K. Find the Kth Smallest element in the BST using O(1) extra space. 

// Example 1:

// Input:
//       2
//     /   \
//    1     3
// K = 2
// Output: 2
// Explanation: 2 is the 2nd smallest element in the BST

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

//-----------MORRIS TRAVERSAL------------
int KthSmallestElement(Node *root, int K) {
    // Morris Traversal
    if(root == nullptr) return -1;
    Node* curr = root, *pred;
    int cnt = 0;
    int res = -1;
    while(curr != nullptr) {
        if(curr->left == nullptr) {
            cnt++;
            if(cnt == K) {
                res = curr->data;
                break;
            }
            
            curr = curr->right;
        }
        else {
            pred = curr->left;
            while(pred->right != nullptr && pred->right != curr) {
                pred = pred->right;
            }
            
            if(pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right = nullptr;
                cnt++;
                if(cnt == K) {
                    res = curr->data;
                    break;
                }
                
                curr = curr->right;
            }
        }
    }
    
    return res;
}

//---------RECURSIVE--------------
void inorder(Node* root, int &k, int &ans){
    if(root == NULL)
    return;
    inorder(root -> left, k, ans);
    k--;
    if(k == 0){
        ans = root -> data;
        return ;
    }
    inorder(root -> right, k, ans);
}
int KthSmallestElement(Node *root, int K) {
    // add code here.
    int ans = -1;
    inorder(root, K, ans);
    return ans;
}