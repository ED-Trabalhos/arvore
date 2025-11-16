#include "arvore.h"

void main() {
    Node *root = NULL;
    int array[20] = {7, 63, 22, 89, 41, 99, 14, 75, 58, 30, 81, 92, 5, 47, 68, 2, 70, 36, 51, 84};
    int i;

    for (i = 0; i < 20; i++) {
        root = insert(root, array[i]);
        //printf("Inserted %d\n", array[i]);
    }

    search(root, 92);
}