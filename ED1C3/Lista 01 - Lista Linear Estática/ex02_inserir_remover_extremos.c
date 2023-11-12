#include <stdio.h>
#include <stdlib.h>
#include "my_int_list.h"

int menu_principal ()
{
    int opcao;

    system("cls");

    printf("[MENU - LISTA LINEAR ESTATICA - INT]");
    printf("\n[1] Inserir elemento no inicio;");
    printf("\n[2] Inserir elemento no final;");
    printf("\n[3] Remover elemento do inicio;");
    printf("\n[4] Remover elemento do final;");
    printf("\n[5] Exibir elementos;");
    printf("\n[-1] Encerrar o Programa.");

    printf("\n\n.. Insira o numero da opcao desejada..: ");
    scanf("%d", &opcao);

    return opcao;
}

void main ()
{
    int elemento;
    int programa_aberto = 1;
    char enter;

    LISTA_INT *Lista = (LISTA_INT*) malloc(sizeof(LISTA_INT));

    lista_int_inicializar(Lista);

    do
    {
        switch (menu_principal())
        {

        case 1:
            printf("\n.. Insira o elemento..: ");
            scanf("%d", &elemento);

            if (!lista_int_inserir_posicao(Lista, 0, elemento))
                printf("\n>> Elemento inserido com sucesso.");

            break;

        case 2:
            printf("\n.. Insira o elemento..: ");
            scanf("%d", &elemento);

            if (!lista_int_inserir_posicao(Lista, Lista -> n+1, elemento));
                printf("\n>> Elemento inserido com sucesso.");

            break;

        case 3:
            if (!lista_int_remover_posicao(Lista, 0))
                printf("\n>> Elemento removido com sucesso.");

            break;

        case 4:
            if (!lista_int_remover_posicao(Lista, Lista -> n))
                printf("\n>> Elemento removido com sucesso.");

            break;

        case 5:
            lista_int_exibir_elementos(Lista);

            break;

        case -1:
            programa_aberto = 0;

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
}
