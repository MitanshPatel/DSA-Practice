#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

//PREORDER
vector<int> preOrder(Node* root){
    vector<int>ans;
    stack<Node *>s;
    s.push(root);
    while(!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp -> data);
        if(temp -> right) s.push(temp -> right);
        if(temp -> left) s.push(temp -> left);
    }
    return ans;
}

//INORDER
vector<int> inOrder(Node* root){
    stack<Node*> st;
    Node* node = root;
    vector<int> ans;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node -> left;
        }
        else{
            if(st.empty())  break;
            node = st.top();
            st.pop();
            ans.push_back(node -> data);
            node = node -> right;    
        }
    }
    return ans;
}

//POSTORDER 2 STACKS
vector<int> postOrder(Node* node) {
    // code here
    stack<Node*>st1;
    stack<Node*>st2;
    vector<int>answer;
    if(node == NULL) return answer;
    
    st1.push(node);
    while(!st1.empty()){
        node=st1.top();
        st1.pop();
        st2.push(node);
        
        if(node->left!=NULL){
            st1.push(node->left);
        }
        if(node->right!=NULL){
            st1.push(node->right);
        }
    }
    while(!st2.empty()){
        answer.push_back(st2.top()->data);
        st2.pop();
    }
    return answer;
}

//POSTORDER 1 STACK


