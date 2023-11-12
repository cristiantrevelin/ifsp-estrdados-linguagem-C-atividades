#include <stdio.h>
#include <stdlib.h>
#include "my_int_deque.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("----------- [MENU - DEQUE - INT] -----------");
    printf("\n[1] Inserir no Inicio;");
    printf("\n[2] Inserir no Fim;");
    printf("\n[3] Remover do Inicio;");
    printf("\n[4] Remover do Fim;");
    printf("\n[5] Realizar Impressao Nao Classica;");
    printf("\n[6] Realizar Impressao Classica;");

    printf("\n\n[-1] Encerrar Programa.");
    printf("\n--------------------------------------------");
    printf("\n.. Insira a opcao..: ");

    scanf("%d", &opcao);

    return opcao;
}

void main ()
{
    int programa_executando = 1;
    int elemento, *elemento_removido;
    char enter;

    INT_DEQUE *Deque = (INT_DEQUE *) malloc(sizeof(INT_DEQUE));
    deque_int_inicializar(Deque);

    do
    {
        switch (menu())
        {

        case 1:
            printf("\n.. Insira o elemento..: ");
            scanf("%d", &elemento);

            if (deque_int_inserir_inicio(Deque, elemento) == 0)
                printf(">> Elemento inserido no inicio com sucesso!");

            break;

        case 2:
            printf("\n.. Insira o elemento..: ");
            scanf("%d", &elemento);

            if (deque_int_inserir_fim(Deque, elemento) == 0)
                printf(">> Elemento inserido no fim com sucesso!");

            break;

        case 3:
            elemento_removido = deque_int_remover_inicio(Deque);

            if (elemento_removido != NULL)
                printf("\n>> Elemento (%d) removido do inicio com sucesso!", *elemento_removido);

            break;

        case 4:
            elemento_removido = deque_int_remover_fim(Deque);

            if (elemento_removido != NULL)
                printf("\n>> Elemento (%d) removido do fim com sucesso!", *elemento_removido);

            break;

        case 5:
            deque_int_imprimir_nc(Deque);
            break;

        case 6:
            deque_int_imprimir(*Deque);
            break;

        case -1:
            programa_executando = 0;
            printf("\n>> Programa encerrado.");

            break;

        default:
            printf("\n>> Opcao invalida, tente novamente.");
            break;
        }

        if (programa_executando)
        {
            fflush(stdin);
            printf("\n\n[PRESSIONE ENTER PARA CONTINUAR]");
            scanf("%c", &enter);
        }

    } while (programa_executando);

    printf("\n");
}
