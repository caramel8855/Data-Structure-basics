#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return createnode(data);
    } else {
        if (root->data > data) {
            root->left = insert(root->left, data);
        } else if (root->data < data) {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

struct node *findMin(struct node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node *deleteNode(struct node *root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = createnode(34);
    struct node *second = createnode(43);
    struct node *third = createnode(78);

    root->left = second;
    root->right = third;

    printf("Original Inorder traversal: \n");
    inorder(root);
    printf("\n");

    int dataToDelete = 34;
    root = deleteNode(root, dataToDelete);

    printf("Inorder traversal after deleting %d: \n", dataToDelete);
    inorder(root);

    return 0;
}