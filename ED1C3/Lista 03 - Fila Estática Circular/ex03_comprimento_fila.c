#include <stdio.h>
#include <stdlib.h>
#include "my_int_queue.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("[MENU - FILA ESTATICA CIRCULAR - INT]: ---------------------------");
    printf("\n[1] Enfileirar elemento;");
    printf("\n[2] Apresentar fila;");
    printf("\n[3] Calcular comprimento atual da fila;");

    printf("\n\n[-1] Encerrar o programa.");
    printf("\n------------------------------------------------------------------");
    printf("\n.. Insira a opcao desejada..: ");
    scanf("%d", &opcao);

    return opcao;
}

void main ()
{
    INT_QUEUE *Fila = (INT_QUEUE *) malloc(sizeof(INT_QUEUE));
    fila_int_inicializar(Fila);

    int programa_executando = 1;
    int elemento, comprimento;
    char pressione_enter;

    do
    {
        switch (menu())
        {
        case 1:
            printf("\n.. Insira o elemento..: ");
            scanf("%d", &elemento);

            if (fila_int_enfileirar(Fila, elemento) == 0)
                printf("\n>> Elemento enfileirado com sucesso!");

            break;

        case 2:
            fila_int_apresentar(*Fila);
            break;

        case 3:
            comprimento = fila_int_calcular_comprimento(*Fila);
            printf("\n>> Comprimento atual da fila: %d", comprimento);
            break;

        case -1:
            programa_executando = 0;
            printf("\n>> Programa Encerrado.");
            break;

        default:
            printf("\n>> Opcao invalida, tente novamente.");
            break;
        }

        if (programa_executando)
        {
            fflush(stdin);
            printf("\n\n[PRESSIONE ENTER PARA CONTINUAR]");
            scanf("%c", &pressione_enter);
        }

    } while (programa_executando);

    printf("\n");
}
