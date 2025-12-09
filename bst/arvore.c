#include "arvore.h"

// Função de inserção de um novo nó
Node* insert(Node *root, int data){
    Node *temp = (Node*)malloc(sizeof(Node));

    // Cria ponteiro de nó temp com o dado passado 
    // na função e os demais filhos como nulo
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    // Verifica se a lista está vazia
    if (root == NULL) {
        root = temp;
        return root;
    }

    // Nós current (atual) e parent (pai) criados
    Node *current = root;
    Node *parent = NULL;

    // Função para quando current == null
    while (current){
        // Antes de mover o current adiante,
        // salvamos seu endereço atual em parent
        parent = current;
        // Verifica se o dado é maior que o do atual
        if (current->data > data) {
            // Vai para o nó da esquerda
            current = current->left;
            // Se chegou ao fim
            if (current == NULL) {
                parent->left = temp;
                return root;
            }

        // Se o dado for menor
        } else {
            // Vai para o nó da direita
            current = current->right;
            if (current == NULL) {
                parent->right = temp;
                return root;
            }
        } 
    }

}

// Imprimir os nós de forma 
// ordenada pela travessia em ordem
void inorder_transversal(Node *root) {
    // Função recursiva
    // Vai empilhando os valores na stack
    // e chamando a função novamente
    if (root) {
        inorder_transversal(root->left);
        printf("|  %-6d |\n", root->data);
        inorder_transversal(root->right);
    }
}

// Função de busca
void search(Node *root, int data) {
    Node *current = root;

    // Enquanto o ponteiro current não for null
    while (current) {
        // Se o dado for maior que o atual,
        // avança a direita, e visse-versa
        if (current->data > data) {
            current = current->left;
        } else if (current->data < data) {
            current = current->right;
        } else {
            printf("Encontrado\n");
            // Encerra a função
            return;
        }
    }

    // Se não for encontrado, o loop encerra
    // por current ser nulo e retorna esta mensagem
    printf("Não encontrado\n");
}

// Função para encontrar o menor valor
// a partir do nó passado como parâmetro
Node* find_min(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        // Segue até o menor da subárvore
        current = current->left;
    }
    return current;
}

// Função para deletar o nó que contém o
// dado passado como parâmetro
Node* delete(Node *root, int data) {
    if (root == NULL) {
        return root;
    }

    Node *current = root;
    Node *parent = NULL;
    
    // Avança pelos nós até encontrar o valor
    // ou chegar ao fim
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    // Se chegou ao fim e não encontrou o valor
    if (current == NULL) {
        printf("Nó com a chave %d não encontrado para exclusão.\n", data);
        return root;
    }

    // Se encontrou o valor  
    // verifica se é um nó com 0 ou 1 filho
    if (current->left == NULL || current->right == NULL) {
        // Nó filho (child) recebe este nó
        Node *child = (current->left != NULL) ? current->left : current->right;
        // Entra se o nó buscado for a raiz da árvore
        if (parent == NULL) {
            // Deleta o nó
            free(current);
            // O filho se torna a nova raíz
            return child;
        }

        // Verifica se o atual é o nó da esquerda ou
        // da direita do parent e substitui pelo nó de child
        if (current == parent->left) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        // Deleta o nó
        free(current);
        
    // Se o nó tiver 2 filhos
    } else {
        // Encontra o menor valor da subárvore do filho á direita
        Node *successor = find_min(current->right);
        // O valor é guardado
        int successor_data = successor->data;
        // O sucessor nunca tem 2 filhos, então não entra neste
        // else e é removido da árvore
        root = delete(root, successor_data);
        // O dado do atual é substituído pelo sucessor in-order deletado
        current->data = successor_data;
    }

    return root;
}

// Imprime o menu
// Retorna a opção desejada
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