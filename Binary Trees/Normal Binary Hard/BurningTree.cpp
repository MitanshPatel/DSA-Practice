// Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
// Note: The tree contains unique values.


// Example 1:
// Input:      
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      6
//        / \      \
//       7   8      9
//                    \
//                    10
// Target Node = 8
// Output: 7
// Explanation: If leaf with the value 
// 8 is set on fire. 
// After 1 sec: 5 is set on fire.
// After 2 sec: 2, 7 are set to fire.
// After 3 sec: 4, 1 are set to fire.
// After 4 sec: 3 is set to fire.
// After 5 sec: 6 is set to fire.
// After 6 sec: 9 is set to fire.
// After 7 sec: 10 is set to fire.
// It takes 7s to burn the complete tree.

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
//--------------METHOD 1: BFS----------------
Node* create(Node* root,map<Node*,Node*> &m,int k){
    Node* res=NULL;
    queue<Node*> q;
    q.push(root);
    m[root]=NULL;//root ka koi baap nhi
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->data==k){
            res=temp;//target node
        }
        if(temp->left){
            m[temp->left]=temp;//father hogya temp
            q.push(temp->left);
        }
        if(temp->right){
            m[temp->right]=temp;
            q.push(temp->right);
        }
    }
    return res;
}
int burn(Node* root,map<Node*,Node*> &m){
    map<Node*,bool> v;
    queue<Node*> q;
    v[root]=true;
    q.push(root);
    int ans=0;
    while(!q.empty()){
        int s=q.size();
        bool flag=0;//it will tell if burning happens
        while(s--){
            Node* temp=q.front();
            q.pop();
            //isme 3 hoge left right and parent
            if(temp->left and !v[temp->left]){
                v[temp->left]=true;
                q.push(temp->left);
                flag=1;
            }
            if(temp->right and !v[temp->right]){
                v[temp->right]=true;
                q.push(temp->right);
                flag=1;
            }
            //now father
            if(!v[m[temp]] and m[temp]){
                flag=1;
                v[m[temp]]=true;
                q.push(m[temp]);
            }
        }
        if(flag==1){
            ans++;
        }
    }
    return ans;
}
int minTime(Node* root, int target) {
    // Your code goes here
    //algo
    //1 map of neighbor yeh dono level of traversal
    // 2 get target node
    // 3 burn //isme ek map of visited and queue
    map<Node*,Node*> m;
    Node* t = create(root,m,target);
    int ans = burn(t,m);
    return ans;
}

//----------------METHOD 2: DFS---------------
int ans=0;
pair<int,bool> dfs(Node* root, int target){
    if(root==NULL){
        return {0, false};
    }
    if(root->data==target){
        ans=max(dfs(root->left, target).first, dfs(root->right, target).first);
        return {1, true};
    }
    pair<int,bool> left = dfs(root->left, target), right = dfs(root->right, target);
    if(left.second){
        ans=max(ans, right.first+left.first);
        return {left.first+1, true};
    } else if(right.second){
        ans=max(ans, right.first+left.first);
        return {right.first+1, true};
    } else {
        return {max(left.first, right.first)+1, false};
    }
}

int minTime(Node* root, int target) {
    dfs(root, target);
    return ans;
}