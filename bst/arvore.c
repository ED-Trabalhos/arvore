#include "arvore.h"

Node* insert(Node *root, int data){
    Node *temp = (Node*)malloc(sizeof(Node));

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
        printf("|  %-6d |\n", root->data);
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
            printf("Encontrado\n");
            return;
        }
    }

    printf("Não encontrado\n");
}

int menu(int choice) {
    printf("+=========================+\n");
    printf("| Árvore de Busca Binária |\n");
    printf("+=========================+\n");
    printf("[1] Inserir\n");
    printf("[2] Procurar\n");
    printf("[3] Imprimir\n");
    printf("[0] Sair\n");
    printf("+=========================+\n");
    printf("Selecione: ");
    scanf("%d", &choice);
    return choice;
}