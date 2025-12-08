#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

void inserir(paciente heap[], int *tamanho, char nome[], int gravidade, char relatorio[]){
    paciente novo;
    strcpy(novo.nome, nome);
    novo.gravidade = gravidade;
    strcpy(novo.relatorio, relatorio);
    heap[*tamanho] = novo;
    *tamanho = *tamanho + 1;
    int indice = *tamanho - 1;
    while(indice > 0){
        int pai = (indice - 1) / 2;
        if (heap[indice].gravidade > heap[pai].gravidade){
            paciente temp = heap[indice];
            heap[indice] = heap[pai];
            heap[pai] = temp;
            indice = pai;
        } else {
            break;
        }
    }
    printf("Paciente %s com gravidade %d inserido com sucesso\n", nome, gravidade);
}

int buscar(paciente heap[], int tamanho, char nome[]){
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(heap[i].nome, nome) == 0) {
            return i; 
        }
    }
    return -1;  
}

void remover(paciente heap[], int *tamanho, char nome[]){
    int indice;
    indice = buscar(heap, *tamanho, nome);
    if (indice == -1){
        printf("\nEsse nome não foi encontrado!\n");
        return;
    }
    printf("\nPaciente %s encontrado!\n", nome);
    heap[indice] = heap[*tamanho - 1];
    (*tamanho)--;
    int posicaoAntes = indice;
    while(indice > 0){
        int pai = (indice - 1) / 2;
        if (heap[indice].gravidade > heap[pai].gravidade){
            paciente temp = heap[indice];
            heap[indice] = heap[pai];
            heap[pai] = temp;
            indice = pai;
        } else {
            break; 
        }
    }
    if (indice == posicaoAntes) { //não subiu, então tentaremos descer para os filhos
            while(2 * indice + 1 < *tamanho){ //enquant tiver pelo menos o filho esquerdo
                int filhoE = 2 * indice + 1;
                int filhoD = 2 * indice + 2;
                int maior = indice; //assume que o pai é o maior
            if (filhoE < *tamanho && heap[filhoE].gravidade > heap[maior].gravidade) { //se o filho esquerdo é maior
                maior = filhoE;
            }
            if (filhoD < *tamanho && heap[filhoD].gravidade > heap[maior].gravidade) { //se o filho direito é maior
                maior = filhoD;
            }
            if (maior == indice) { //se o maior for igual o do indice já esta na posição correta
                break;
            }
            paciente temp = heap[indice];
            heap[indice] = heap[maior];
            heap[maior] = temp;
            indice = maior; //para continuar descendo na heap
        }
    }
    printf("Paciente removido com sucesso!\n");
}

void listar(paciente heap[], int tamanho){
    if (tamanho == 0){
        printf("Nenhum paciente na fila!\n");
        return;
    }
    printf("\n========== FILA DE ESPERA ==========\n");
    for (int i = 0; i < tamanho; i++){
        printf("Paciente %d, %s\n", i+1, heap[i].nome);
        printf("Gravidade: %d\n", heap[i].gravidade);
        printf("Relatório: %s\n", heap[i].relatorio);
        printf("===================================\n");
    }
}