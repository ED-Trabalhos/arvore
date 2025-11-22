#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    int column;
    int row;
    struct Node *left;
    struct Node *right;
} Node;

Node* insert(Node *root, int data);
void inorder_transversal(Node *root);
void search(Node *search, int data);