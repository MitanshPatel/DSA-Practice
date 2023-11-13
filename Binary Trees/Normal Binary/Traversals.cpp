//preorder, inorder, postorder

#include <bits/stdc++.h>
using namespace std;

// C++ program for different tree traversals
#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data, pointer to left child
// and a pointer to right child
struct Node {
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// INORDER
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	// First recur on left child
	printInorder(node->left);

	// Then print the data of node
	cout << node->data << " ";

	// Now recur on right child
	printInorder(node->right);
}

// PREORDER
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // First print data of node
    cout << node->data << " ";
 
    // Then recur on left subtree
    printPreorder(node->left);
 
    // Now recur on right subtree
    printPreorder(node->right);
}

// POSTORDER
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // First recur on left subtree
    printPostorder(node->left);
 
    // Then recur on right subtree
    printPostorder(node->right);
 
    // Now deal with the node
    cout << node->data << " ";
}

//LEVEL ORDER / BFS
vector<int> levelOrder(Node* node){   
    Node* temp;
    queue<Node*>q;
    vector<int>v;
    q.push(node);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        v.push_back(temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return v;
}    

// Driver code
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	// Function call
	cout << "Inorder traversal of binary tree is \n";
	printInorder(root);

	return 0;
}

