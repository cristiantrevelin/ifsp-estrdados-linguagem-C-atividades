#include <stdio.h>
#include <stdlib.h>
#include "my_int_stack.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("[MENU - PILHAS INT]:");
    printf("\n[0] Empilhar Elemento;");
    printf("\n[1] Apresentar Pilha P;");
    printf("\n[2] Apresentar Pilha N;");
    printf("\n[-1] Encerrar Programa.");

    printf("\n\n.. Insira a opcao desejada..: ");
    scanf("%d", &opcao);

    return opcao;
}

void main ()
{
    int programa_executando = 1;
    int elemento;
    char pressione_enter;

    INT_STACK *P = (INT_STACK *) malloc(sizeof(INT_STACK));
    INT_STACK *N = (INT_STACK *) malloc(sizeof(INT_STACK));

    pilha_int_inicializar(P);
    pilha_int_inicializar(N);

    do
    {
        switch (menu())
        {

        case 0:
            printf("\n.. Insira o elemento..: ");
            scanf("%d", &elemento);

            if (elemento > 0)
            {
                if (pilha_int_push(P, elemento) == 0)
                    printf("   >> Elemento empilhado na pilha P!");
            }
            else if (elemento < 0)
            {
                if (pilha_int_push(N, elemento) == 0)
                    printf("   >> Elemento empilhado na pilha N!");
            }
            else
            {
                if (pilha_int_pop(P) == 0)
                    printf("\n   >> Elemento desempilhado da pilha P!");
                if (pilha_int_pop(N) == 0)
                    printf("\n   >> Elemento desempilhado da pilha N!");
            }

            break;

        case 1:
            printf("\n[PILHA P]");
            pilha_int_apresentar(P);

            break;

        case 2:
            printf("\n[PILHA N]");
            pilha_int_apresentar(N);

            break;

        case -1:
            printf("\n>> Encerrando...");
            programa_executando = 0;

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
