#include "arvore.h"

Node* insert(Node *root, int data){
    Node *temp = malloc(sizeof(Node*));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL) {
        root = temp;
        return root;
    }

    Node *current = root;
    Node *parent = NULL;

    while (current){
        parent = current;
        if (current->data > data) {
            current = current->left;

            if (current == NULL) {
                parent->left = temp;
                return root;
            }

        } else {
            current = current->right;
            if (current == NULL) {
                parent->right = temp;
                return root;
            }
        } 
    }

}

void inorder_transversal(Node *root) {
    if (root) {
        inorder_transversal(root->left);
        printf("%d ", root->data);
        inorder_transversal(root->right);
    }
}

void search(Node *root, int data) {
    Node *current = root;

    while (current) {
        if (current->data > data) {
            current = current->left;
        } else if (current->data < data) {
            current = current->right;
        } else {
            printf("%d found.", data);
            return;
        }
    }

    printf("%d not found.", data);
}