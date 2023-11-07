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

void preorder(struct node *root){
    if(root != NULL){
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main (){
    struct node *root = createnode(34);
    struct node *second = createnode(43);
    struct node *third = createnode(78);

    root->left = second;
    root->right = third; 
    printf("Preorder traversal: \n");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: \n");
    postorder(root);
    printf("\n");
    
    printf("Inorder traversal: \n");
    inorder(root);
}