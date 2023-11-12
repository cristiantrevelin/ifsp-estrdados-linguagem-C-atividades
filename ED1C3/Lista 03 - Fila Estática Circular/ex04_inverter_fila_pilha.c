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
    printf("\n[3] Inverter ordem dos elementos da fila;");
    printf("\n[4] Reiniciar fila;");

    printf("\n\n[-1] Encerrar o programa.");
    printf("\n------------------------------------------------------------------");
    printf("\n.. Insira a opcao desejada..: ");
    scanf("%d", &opcao);

    return opcao;
}

void main ()
{
    int programa_aberto = 1;
    int elemento;
    char enter;

    INT_QUEUE *Fila = (INT_QUEUE *) malloc(sizeof(INT_QUEUE));
    fila_int_inicializar(Fila);

    do
    {
        switch (menu())
        {
        case 1:
            printf("\n.. Insira o elemento..: ");
            scanf("%d", &elemento);

            if (fila_int_enfileirar(Fila, elemento) == 0)
                printf(">> Elemento enfileirado com sucesso!");
            break;

        case 2:
            fila_int_apresentar(*Fila);
            break;

        case 3:
            if (fila_int_inverter(Fila) == 0)
                printf("\n>> Fila invertida com sucesso!");
            break;

        case 4:
            fila_int_inicializar(Fila);
            printf("\n>> Fila reiniciada!");
            break;

        case -1:
            programa_aberto = 0;
            printf("\n>> Programa encerrado.");
            break;

        default:
            printf("\n>> Opcao invalida, tente novamente.");
            break;
        }

        if (programa_aberto)
        {
            fflush(stdin);
            printf("\n\n[PRESSIONE ENTER PARA CONTINUAR]");
            scanf("%c", &enter);
        }

    } while (programa_aberto);

    printf("\n");
}
