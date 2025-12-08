#ifndef HEAP_H
#define HEAP_H

typedef struct paciente{
    char nome[50];
    int gravidade;
    char relatorio[200];
}paciente;

void inserir(paciente heap[], int *tamanho, char nome[], int gravidade, char relatorio[]);
void remover(paciente heap[], int *tamanho, char nome[]);
int buscar(paciente heap[], int tamanho, char nome[]);
void listar(paciente heap[], int tamanho);

#endif