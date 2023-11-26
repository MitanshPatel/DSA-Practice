// Given two BSTs, return elements of both BSTs in sorted form.
// Example 1:
// Input:
// BST1:
//        5
//      /   \
//     3     6
//    / \
//   2   4  
// BST2:
//         2
//       /   \
//      1     3
//             \
//              7
//             /
//            6
// Output: 1 2 2 3 3 4 5 6 6 7

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

//---------METHOD 1 VECTOR----------
void inorder(vector<int> &v,Node* root){
    if(!root) return;
    inorder(v,root->left);
    v.push_back(root->data);
    inorder(v,root->right);
}
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> v1,v2;
    inorder(v1,root1);
    inorder(v2,root2);
    int i = 0;
    int j =0;
    int N = v1.size();
    int M = v2.size();
    vector<int> answer;
    
    while(i<N && j<M) {
        if(v1[i] < v2[j])
            answer.push_back(v1[i++]);
        else if(v1[i] > v2[j])
            answer.push_back(v2[j++]);
        else if(v1[i] == v2[j])
            answer.push_back(v1[i++]);

    }
    while(i<N)
        answer.push_back(v1[i++]);
    while(j<M)
        answer.push_back(v2[j++]);
    return answer;
}

//--------------METHOD 2 STACK--------------
vector<int> merge(Node *root1, Node *root2){
    //Your code here
    vector<int>ans;
    stack<Node *>s1,s2;
    while(root1 || root2 || s1.size() || s2.size()){
        while(root1){
            s1.push(root1);
            root1=root1->left;
        }
        while(root2){
            s2.push(root2);
            root2=root2->left;
        }
        if(s2.empty()|| (s1.size()&&s1.top()->data<s2.top()->data)){
            root1=s1.top();
            ans.push_back(root1->data);
            s1.pop();
            root1=root1->right;
        }
        else{
            root2=s2.top();
            ans.push_back(root2->data);
            s2.pop();
            root2=root2->right;
        }
    }
    return ans;
}

