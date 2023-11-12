#include <stdio.h>
#include <stdlib.h>
#include "my_int_stack.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("[MENU - PILHA INT]:");
    printf("\n[0] Preencher Pilha;");
    printf("\n[1] Esvaziar Pilha Apresentando os Elementos;");
    printf("\n[-1] Encerrar Programa.");

    printf("\n\n.. Insira a opcao desejada..: ");
    scanf("%d", &opcao);

    return opcao;
}

void main ()
{
    int programa_executando = 1;
    char pressione_enter;

    INT_STACK *Pilha = (INT_STACK *) malloc(sizeof(INT_STACK));

    pilha_int_inicializar(Pilha);

    do
    {
        switch (menu())
        {

        case 0:
            pilha_int_preencher_par_impar(Pilha);
            break;

        case 1:
            if (pilha_int_esvaziar_apresentando(Pilha) == 1)
                printf("\n>> Nao ha elementos na Pilha.");
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
