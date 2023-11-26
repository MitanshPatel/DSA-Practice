//left child is less than root and right child is greater than root then it is BST

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *createNode(int n){
    Node *newNode;
    newNode=(Node*)malloc(sizeof(Node));
    newNode->data=n;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//---------INORDER BST----------
void inOrder(Node *root){    
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

//-------CHECK FOR BST-------
int isBSTpt2 (Node *root, int min, int max){
    if(root==NULL){
        return 1;
    }
    if((root->data<=min) || (root->data>max)){  //left subtree is not less than root or right subtree is not greater than root then it is not BST
        return 0;
    }
    return isBSTpt2(root->left,min,root->data) && isBSTpt2(root->right,root->data,max);  
    
}

int isBST(Node *root){  //this function is just to put min = INT_MIN and max = INT_MAX for function isBSTpt2
    return isBSTpt2(root,INT_MIN,INT_MAX);
}

//-------SEARCH--------
Node *search(Node *root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data > key){
        return search(root->left,key); // there is no change in subtree during searching so there is no update compared to line 69 or 72
    }
    
    return search(root->right,key);  // there is no change in subtree during searching so there is no update compared to line 69 or 72
}

//-------INSERT--------
Node *insert(Node *root, int key){
    if(root==NULL){
        return createNode(key);
    }
    if(root->data==key){
        printf("Cannot add %d, as it is already in BST\n",key);
    }
    else if(root->data>key){
        root->left=insert(root->left,key);  // inserting is changing the left subtree, so it will return to root->left so it gets updated 
    }
    else if(root->data<key){
        root->right=insert(root->right,key);  // inserting is changing the left subtree, so it will return to root->left so it gets updated 
    }
    
    return root;
}

//--------FIND MIN VAL-----------
Node* minValueNode(Node* root){
    Node* current = root;
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}

//--------DELETE-----------
Node *delet(Node *root, int key){
    // base case
    if (root == NULL)
        return root;
  
    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->data)
        root->left = delet(root->left, key);
  
    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->data)
        root->right = delet(root->right, key);

    // to delete the node: 
    else {
        // node has no child
        if (root->left==NULL && root->right==NULL){
            return NULL;  //will be returned to line 95 or 99 and gets connected to the tree automatically
        }
        // node with only one child
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp; //will be returned to line 95 or 99 and gets connected to the tree automatically
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp; //will be returned to line 95 or 99 and gets connected to the tree
        }
  
        // node with two children: Get the inorder successor (smallest in the RIGHT subtree)
        Node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor(now present in leftmost/smallest node in RIGHT subtree) so connect it with root->right as the subtree is getting updated
        root->right = delet(root->right, temp->data);
    }
    return root;
}

int main(){
    Node *p = createNode(5);
    Node *p1 = createNode(3);
    Node *p2 = createNode(7);
    Node *p3 = createNode(1);
    Node *p4 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   7
    //   / \
    //  1   4  

    insert(p,6);
    insert(p,9);
    insert(p,8);
    inOrder(p);
    printf("\n");
    delet(p,5);
    inOrder(p);
    printf("\n");
    if(isBST(p)==1){
        printf("It is a Binary search tree\n");
    }
    else printf("Not a binary search tree\n");

    
    if(search(p,3)==NULL){
        printf("key doesn't exist\n");
    }
    else printf("key exists\n");
} 








//Method 2 FOR INSERTION 

// void insert(Node *root, int key){
//    Node *prev = NULL;
//    while(root!=NULL){
//        prev = root;
//        if(key==root->data){
//            printf("Cannot insert %d, already in BST", key);
//            return;
//        }
//        else if(key<root->data){
//            root = root->left;
//        }
//        else{
//            root = root->right;
//        }
//    }
//    Node* new = createNode(key);
//    if(key<prev->data){
//        prev->left = new;
//    }
//    else{
//        prev->right = new;
//    }

// }