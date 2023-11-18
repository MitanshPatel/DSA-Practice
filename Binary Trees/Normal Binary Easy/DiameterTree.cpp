// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int solve(Node * root,int &ans){
    if(root == NULL)return 0;
    int left = solve(root->left,ans);
    int right = solve(root->right,ans);
    ans  = max(ans,left+right+1);
    return max(left,right)+1;
}
int diameter(Node* root) {
    // Your code here
    int ans = 0;
    solve(root,ans);
    return ans;
}