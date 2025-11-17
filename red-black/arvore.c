#include "arvore.h"

void initialize_NIL() {
    NIL = (Node*)malloc(sizeof(Node));
    NIL->color = BLACK;
    NIL->key = 0;
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->parent = NIL;
}

Node* insert(Node *root, int key) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->color = RED;
    temp->left = NIL;
    temp->right = NIL;
    temp->parent = NIL;

    if (root == NIL) {
        root = temp;
        return root;    
    }

    Node *current = root;
    Node *parent = NIL;

    while (current != NIL) {
        parent = current;

        if (key < current->key) {
            current = current->left;
            
            if (current == NIL) {
                temp->parent = parent;
                parent->left = temp;
                //printf("%d ", temp->key);
                return root;
            }

        } else {
            current = current->right;
            if (current == NIL) {
                temp->parent = parent;
                parent->right = temp;
                //printf("%d ", temp->key);
                return root;
            }
        }
    }
}

void inorder_transversal(Node *root) {
    if (root != NIL) {
        inorder_transversal(root->left);
        printf("%d ", root->key);
        inorder_transversal(root->right);
    }
}