#include <stdio.h>
#include <stdlib.h>
#include "my_int_list.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("[MENU - LISTA LINEAR ESTATICA - INT]");
    printf("\n[1] Inserir elemento na lista;");
    printf("\n[2] Exibir lista;");
    printf("\n[3] Concatenar listas;");
    printf("\n[-1] Encerrar o Programa.");

    printf("\n\n.. Insira o numero da opcao desejada..: ");
    scanf("%d", &opcao);

    return opcao;
}

void main ()
{
    typedef char String[50];
    int programa_aberto = 1;
    int posicao, elemento, numero_lista;
    char enter;

    LISTA_INT *Lista1 = (LISTA_INT*) malloc(sizeof(LISTA_INT));
    LISTA_INT *Lista2 = (LISTA_INT*) malloc(sizeof(LISTA_INT));

    lista_int_inicializar(Lista1);
    lista_int_inicializar(Lista2);

    do
    {
        switch (menu())
        {

        case 1:
            printf("\n.. Em qual lista deseja inserir? (1 ou 2)..: ");
            scanf("%d", &numero_lista);

            printf(".. Insira a posicao..: ");
            scanf("%d", &posicao);

            printf(".. Insira o elemento..: ");
            scanf("%d", &elemento);

            if (numero_lista == 1)
            {
                if(!lista_int_inserir_posicao(Lista1, posicao, elemento))
                    printf("\n>> Elemento inserido com sucesso.");
            }
            else if (numero_lista == 2)
            {
                if(!lista_int_inserir_posicao(Lista2, posicao, elemento))
                    printf("\n>> Elemento inserido com sucesso.");
            }
            else
                printf("\n>> Erro - Lista invalida.");

            break;

        case 2:
            printf(".. Qual lista deseja exibir? (1 ou 2)..: ");
            scanf("%d", &numero_lista);

            if (numero_lista == 1)
                lista_int_exibir_elementos(Lista1);

            else if (numero_lista == 2)
                lista_int_exibir_elementos(Lista2);

            else
                printf("\n>> Erro - Lista invalida.");

            break;

        case 3:
            if (!lista_int_concatenar_listas(Lista1, Lista2))
                printf("\n>> Listas concatenadas com sucesso!");

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
