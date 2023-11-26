#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

typedef struct Node Node;

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int getHeight(Node *n){
    if(n==NULL){
        return 0;
    }
    return 1+max(getHeight(n->left),getHeight(n->right));
}

Node *createNode(int key){
    Node *n=(Node*)malloc(sizeof(Node));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
    n->height=0;
    return n;
}

int getBalanceFactor(Node *n){
    if (n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

Node *rightRotate(Node *y){  //right rotate subtree rooted with y [ / ]
    Node *x=y->left;
    Node *T2=x->right;

    x->right=y;  //perform rotation
    y->left=T2;

    x->height=getHeight(x); //updating the height
    y->height=getHeight(y);

    return x; //new root
}

Node *leftRotate(Node *x){  // [ \ ]
    Node *y=x->right;
    Node *T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=getHeight(x); //updating the height
    y->height=getHeight(y);

    return y;
}

Node *insert(Node *node, int key){

    //normal BST insertion
    if (node == NULL){
        return (createNode(key));
    }
    if (key < node->key){
        node->left = insert(node->left, key);
    }
    else if (key > node->key){
        node->right = insert(node->right, key);
    }
    else{      // Equal keys are not allowed in BST
        return node;
    }
    node->height=getHeight(node);

    // //Get the balance factor of this ancestor node to check whether this node became unbalanced
    int bf=getBalanceFactor(node);

    //if it is unbalanced, four cases.

    //Left Left case
    if(bf>1 && key < node->left->key){  //bf>1 says that it is longer in left subtree and second condition says that key has been inserted at left of left subtree.
        return rightRotate(node); //pulling the tree from left to right to make it balanced
    }

    //Right Right case
    if(bf<-1 && key > node->right->key){  //bf<-1 means it is longer in right subtree and second condition says key has been inserted at right of right subtree
        return leftRotate(node);  //pulling tree from right to left to make it balanced
    }

    //Left Right case
    if(bf>1 && key > node->left->key){  //second condition says key has been inserted at right of left subtree
        node->left=leftRotate(node->left);  // converting [ < to / ]  (representing binary tree with 3 nodes)
        return rightRotate(node);
    }

    //Right Left case
    if(bf<-1 && key < node->right->key){  //second condition says key has been inserted at left of right subtree
        node->right=rightRotate(node->right); // converting [ > to \ ]*
        return leftRotate(node);
    }
    //Update height of ancestor node after adding 
 

    return node; //return unchanged node pointer
}

void preOrder(Node *root){
    
    if(root!=NULL){
        printf("%d ",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    Node *root = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
              30
             /  \
            20   40
           /  \    \
          10  25    50
    */

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    return 0;
}