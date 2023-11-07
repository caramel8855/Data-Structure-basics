//A binary tree is a binary search tree if, for each node:

//Values in the left subtree are less than the node's value.
//Values in the right subtree are greater than the node's value.
//No duplicate values are allowed.
//Both left and right subtrees are binary search trees.
//Inorder traversal of a binary search tree is always sorted in ascending order.



#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data){
    struct node *n;
    n = (struct node *)malloc (sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int isBST(struct node *root){
    static struct node  *prev = NULL;
    if(root!=NULL){
        if(!isBST (root->left)){
        return 0;
    }
    if(prev!=NULL && prev->data >= root->data){
        return 0 ;
    }
    prev = root;
    return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main (){
    struct node *root = createnode(50);
    struct node *p1 = createnode(40);
    struct node *p2 = createnode(80);
    struct node *p3 = createnode(30);
    struct node *p4 = createnode(45);
    struct node *p5 = createnode(70);
    struct node *p6 = createnode(100);


    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    printf("Preorder traversal: \n");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: \n");
    postorder(root);
    printf("\n");
    
    printf("Inorder traversal: \n");
    inorder(root);

    if(isBST(root)){
        printf("\nIts a binary search tree");
    } else {
        printf("\nIts is not a binary search tree");
    }
}