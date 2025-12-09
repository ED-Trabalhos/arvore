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

Node* find_min(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* delete(Node *root, int data) {
    if (root == NULL) {
        return root;
    }

    Node *current = root;
    Node *parent = NULL;
    
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (current == NULL) {
        printf("Nó com a chave %d não encontrado para exclusão.\n", data);
        return root;
    }
    // Caso 1: Nó com 0 ou 1 filho
    if (current->left == NULL || current->right == NULL) {
        Node *child = (current->left != NULL) ? current->left : current->right;
        if (parent == NULL) {
            free(current);
            return child;
        }

        if (current == parent->left) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        
        free(current);
        
    } else {
        // Caso 2: Nó com 2 filhos
        Node *successor = find_min(current->right);
        int successor_data = successor->data;
        root = delete(root, successor_data);
        current->data = successor_data;
    }

    return root;
}

int menu(int choice) {
    printf("+=========================+\n");
    printf("| Árvore de Busca Binária |\n");
    printf("+=========================+\n");
    printf("[1] Inserir\n");
    printf("[2] Procurar\n");
    printf("[3] Imprimir\n");
    printf("[4] Deletar\n");
    printf("[0] Sair\n");
    printf("+=========================+\n");
    printf("Selecione: ");
    scanf("%d", &choice);
    return choice;
}