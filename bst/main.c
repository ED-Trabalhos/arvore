#include "arvore.h"

void main() {
    Node *root = NULL;
    int i, choice, data;
    bool exit;

    while (exit == false){
        system("clear");
        switch (menu(choice)) {
        case 1:
            printf("+=========================+\n");
            printf("Número: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("+=========================+\n");
            printf("Número: ");
            scanf("%d", &data);
            search(root, data);
            break;
        case 3:
            printf("+=========+\n");
            printf("| Números |\n");
            printf("+=========+\n");
            inorder_transversal(root);
            printf("+=========+\n");
            break;
        default:
            exit = true;
            break;
        }
        printf("Pressione [ENTER] para continuar ");
        getchar();
        getchar();
    }
}