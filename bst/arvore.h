#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
Node* find_min(Node* node);
Node* delete(Node *root, int data);
int menu(int choice);