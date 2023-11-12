#include <stdio.h>
#include <stdlib.h>
#include "my_float_list.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("[MENU - LISTA LINEAR ESTATICA - FLOAT]");
    printf("\n[1] Inserir elemento mantendo a ordem crescente;");
    printf("\n[2] Remover elemento desejado;");
    printf("\n[3] Exibir elementos;");
    printf("\n[-1] Encerrar o Programa.");

    printf("\n\n.. Insira o numero da opcao desejada..: ");
    scanf("%d", &opcao);

    return opcao;
}

void main ()
{
    float elemento;
    int programa_aberto = 1;    ///boolean
    int elementos_removidos;
    char enter;

    LISTA_FLOAT *Lista = (LISTA_FLOAT*) malloc(sizeof(LISTA_FLOAT));

    lista_float_inicializar(Lista);

    do
    {
        switch (menu())
        {

        case 1:
            printf("\n.. Insira o elemento..: ");
            scanf("%f", &elemento);

            if (!lista_float_inserir_ordem_crescente(Lista, elemento))
                printf("\n>> Elemento inserido com sucesso!");

            break;

        case 2:
            printf("\n.. Insira o elemento..: ");
            scanf("%f", &elemento);

            elementos_removidos = lista_float_remover_elemento(Lista, elemento);

            if (elementos_removidos)
                printf("\n>> Quantidade de elementos removidos: %d", elementos_removidos);
            else
                printf("\n>> Elemento nao encontrado.");

            break;

        case 3:
            lista_float_exibir_elementos(Lista);

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
