#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int key;
    Color color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// This tells the compiler, "This variable exists, but it's defined in another file. Just trust me."
extern Node* NIL;

void initialize_NIL();
Node* insert(Node *root, int key);
void inorder_transversal(Node *root);