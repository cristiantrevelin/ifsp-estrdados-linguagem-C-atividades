#include <stdio.h>
#include "ct_input.h"
#include "lista_char.h"

// lciu: lista de char IU.

void lciu_exibir(LISTA_C *lista)
{
    if (lc_vazia(lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n>> Exibindo lista:");

        for (int i = 0; i <= lista -> n; i++)
            printf("\n\t> Elemento [%d]: %c", i, lista -> valores[i]);
    }
}

void lciu_preencher_aleatorio(LISTA_C *lista)
{
    char char_inicial, char_final;

    printf("\n>> Preenchendo lista com valores aleatorios.");
    printf("\n>> Definindo faixa de caracteres:");

    ct_uscanchar(&char_inicial, "\n\t.. Insira o caractere inicial..: ", "\t\t> Valor invalido.");
    ct_uscanchar(&char_final, "\t.. Insira o caractere final..: ", "\t\t> Valor invalido.\n");

    lc_preencher_aleatorio(lista, char_inicial, char_final);

    printf("\n>> Lista preenchida!");
}

void lciu_ordenar(LISTA_C *lista, int (*funcao_ordenacao)(LISTA_C *, int *))
{
    int status, qnt_passos;
    LISTA_C lista_aux;

    if (lc_copiar(lista, &lista_aux) == 1)
        printf("\n>> Lista vazia.");
    else
    {
        status = funcao_ordenacao(&lista_aux, &qnt_passos);

        if (status == 1)
            printf("\n>> A lista possui um unico elemento.");
        else
        {
            printf("\n>> Lista ordenada com sucesso!");
            printf("\n>> Quantidade de passos realizados: %d", qnt_passos);

            printf("\n\n>> Lista original:");
            lciu_exibir(lista);

            printf("\n\n>> Lista ordenada:");
            lciu_exibir(&lista_aux);
        }
    }
}

int lciu_menu()
{
    int opcao;

    system("cls");

    printf("---------- [MENU - LISTA DE CHAR] ----------");
    printf("\n[1] Preencher lista;");
    printf("\n[2] Exibir lista;");
    printf("\n[3] Realizar INSERTION SORT;");
    printf("\n[4] Realizar SHELL SORT;");

    printf("\n\n[0] Encerrar menu.");
    printf("\n--------------------------------------------");

    do
    {
        ct_uscanint(&opcao, "\n.. Insira a opcao..: ", "\t> Valor invalido.");

        if (opcao < 0 || opcao > 4)
            printf("\t> Opcao invalida.");

    } while (opcao < 0 || opcao > 4);

    return opcao;
}

void lciu_executar_menu(LISTA_C *lista)
{
    int programa_executando = 1;
    char enter;

    while (programa_executando)
    {
        switch(lciu_menu())
        {
        case 0:
            programa_executando = 0;
            break;

        case 1:
            lciu_preencher_aleatorio(lista);
            break;

        case 2:
            lciu_exibir(lista);
            break;

        case 3:
            lciu_ordenar(lista, lc_insertion_sort);
            break;

        case 4:
            lciu_ordenar(lista, lc_shell_sort);
            break;

        default:
            break;
        }

        if (programa_executando)
            ct_scanchar(&enter, "\n\n[PRESSIONE ENTER PARA CONTINUAR]");
    }

    printf("\n>> Menu encerrado.\n");
}
