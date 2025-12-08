#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int main(){
    paciente heap[100];
    int tamanho = 0;
    char n;
    do {
        system("clear");
        printf("=============== MENU ===============\n");
        printf("[0] Sair\n");
        printf("[1] Inserir paciente\n");
        printf("[2] Remover paciente\n");
        printf("[3] Listar pacientes\n");
        printf("[4] Buscar paciente\n");
        printf("====================================\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &n);
        getchar();

        switch(n){
            case '0':
                printf("Código finalizado!\n");
                break;
            
            case '1': {
                char nome[50];
                int gravidade;
                char relatorio[200];
                printf("Qual o nome do paciente: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                do {
                    printf("Qual a gravidade do paciente? (1-5): ");
                    scanf("%d", &gravidade);
                    getchar();
        
                    if (gravidade < 1 || gravidade > 5) {
                        printf("Gravidade inválida, digite um valor entre 1 e 5\n");
                    }
                } while (gravidade < 1 || gravidade > 5);
                printf("Faça um breve relatório do paciente: ");
                fgets(relatorio, 200, stdin);
                relatorio[strcspn(relatorio, "\n")] = '\0';
                inserir(heap, &tamanho, nome, gravidade, relatorio);
                printf("\nPressione ENTER para continuar...");
                getchar(); 
                break;
            }
            
            case '2': {
                if (tamanho == 0){
                    printf("\nA lista está vazia, não há nada para remover\n");
                    printf("\nPressione ENTER para continuar...");
                    getchar(); 
                    break;
                }
                char nome[50];
                printf("Digite o nome do paciente que deseja remover: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                remover(heap, &tamanho, nome);
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;
            }
            
            case '3': {
                listar(heap, tamanho);
                printf("\nPressione ENTER para continuar...");
                getchar(); 
                break;  
            }

            case '4': {
                if (tamanho == 0){
                    printf("\nA lista está vazia, não há nada para buscar\n");
                    printf("\nPressione ENTER para continuar...");
                    getchar(); 
                    break;
                }
                char nome[50];
                printf("Digite o nome do paciente que quer buscar:\n");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                int indice = buscar(heap, tamanho, nome);
                if(indice != -1){
                    printf("\nPaciente encontrado com sucesso!\n");
                    printf("Nome: %s\n", heap[indice].nome);
                    printf("Gravidade: %d\n", heap[indice].gravidade);
                    printf("Relatorio: %s\n", heap[indice].relatorio);
                } else {
                    printf("Paciente não encontrado!\n");
                }
                printf("\nPressione ENTER para continuar...");
                getchar(); 
                break;
            }

            default:
                printf("Opção invalida!\n");
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;
        }
        
    } while(n != '0');
    return 0;
}