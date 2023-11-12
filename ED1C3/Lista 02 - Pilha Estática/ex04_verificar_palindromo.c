#include <stdio.h>
#include <stdlib.h>
#include "my_char_stack.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("[MENU - PILHA CHAR]:");
    printf("\n[0] Inserir Palavra na Pilha;");
    printf("\n[1] Apresentar Pilha;");
    printf("\n[2] Verificar Palindromo;");
    printf("\n[-1] Encerrar Programa.");

    printf("\n\n.. Insira a opcao desejada..: ");
    scanf("%d", &opcao);

    return opcao;
}

void main ()
{
    int programa_executando = 1, palindromo;
    int cont_caracteres = 0;
    char pressione_enter;

    CHAR_STACK *Pilha = (CHAR_STACK *) malloc(sizeof(CHAR_STACK));

    pilha_char_inicializar(Pilha);

    do
    {
        switch (menu())
        {

        case 0:
            cont_caracteres = pilha_char_push_palavra(Pilha);
            printf("\n>> Quantidade de caracteres inseridos na Pilha: %d", cont_caracteres);
            break;

        case 1:
            pilha_char_apresentar(Pilha);
            break;

        case 2:
            palindromo = pilha_char_verificar_palindromo(Pilha);

            if (palindromo == 1)
                printf("\n>> A palavra inserida eh um palindromo!");
            else if (palindromo == 0)
                printf("\n>> A palavra inserida nao eh um palindromo.");

            break;

        case -1:
            programa_executando = 0;
            printf("\n>> Encerrando...");
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
