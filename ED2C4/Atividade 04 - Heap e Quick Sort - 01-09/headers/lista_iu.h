#include <stdio.h>
#include "lista.h"
#include "ct_input.h"

void lintiu_exibir (LISTA_INT *lista)
{
    if (lint_vazia(lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n>> Exibindo Lista:");

        for (int i = 0; i <= lista -> n; i++)
            printf("\n\t> Elemento %d: %d", i, lista -> valores[i]);
    }
}

void lintiu_preencher_aleatorio(LISTA_INT *lista)
{
    int int_inicial, int_final;

    printf("\n>> Preenchendo lista com valores aleatorios.");
    printf("\n>> Definindo faixa de valores:");

    ct_uscanint(&int_inicial, "\n\t.. Insira o valor inicial..: ", "\t\t> Valor invalido.");
    ct_uscanint(&int_final, "\t.. Insira o valor final..: ", "\t\t> Valor invalido.\n");

    lint_preencher_aleatorio(lista, int_inicial, int_final);

    printf("\n>> Lista preenchida!");
}

void lintiu_ordenar (LISTA_INT *lista, int (*funcao_ordenacao)(LISTA_INT *, int *))
{
    int status, qnt_passos;

    LISTA_INT copia;

    if (lint_vazia(lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n>> Lista Original:");
        lintiu_exibir(lista);

        lint_copiar(lista, &copia);

        printf("\n\n>> Ordenando Lista:");
        status = funcao_ordenacao(&copia, &qnt_passos);

        if (status == 0)
        {
            printf("\n>> Lista ordenada com sucesso!");
            printf("\n>> Quantidade de passos realizados: %d", qnt_passos);
        }

        else
            printf("\n>> Nao foi possivel ordenar a lista.");

        lintiu_exibir(&copia);
    }
}

void lintiu_quicksort (LISTA_INT *lista)
{
    int qnt_passos;

    //LISTA_INT copia;

    if (lint_vazia(lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n>> Lista Original:");
        lintiu_exibir(lista);

        //lint_copiar(lista, &copia);

        printf("\n\n>> Ordenando Lista:");
        //lint_quicksort(&copia, 0, copia.n, &qnt_passos);
        lint_quicksort(lista, 0, lista -> n, &qnt_passos);


        printf("\n>> Lista ordenada com sucesso!");
        printf("\n>> Quantidade de passos realizados: %d", qnt_passos);

        //lintiu_exibir(&copia);
        lintiu_exibir(lista);
    }
}

void lintiu_busca_binaria (LISTA_INT *lista)
{
    int posicao, chave, qnt_passos = 0;

    if (lint_vazia(lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n>> Realizando Busca Binaria:");
        ct_uscanint(&chave, "\n.. Insira a chave de busca..: ", "\t> Valor invalido.");

        posicao = lint_busca_binaria(lista, 0, lista -> n, chave, &qnt_passos);

        if (posicao == -1)
            printf("\n>> Chave nao encontrada.");
        else
            printf("\n>> Chave encontrada na posicao: %d", posicao);

        printf("\n>> Quantidade de passos realizados: %d", qnt_passos);
    }
}

int lintiu_menu()
{
    int opcao;

    system("cls");

    printf("---------- [MENU - LISTA DE INTS] ----------");
    printf("\n[1] Preencher lista;");
    printf("\n[2] Exibir lista;");
    printf("\n[3] Realizar HEAP SORT;");
    printf("\n[4] Realizar QUICK SORT;");
    printf("\n[5] Realizar BUSCA BINARIA;");

    printf("\n\n[0] Encerrar menu.");
    printf("\n--------------------------------------------");

    do
    {
        ct_uscanint(&opcao, "\n.. Insira a opcao..: ", "\t> Valor invalido.");

        if (opcao < 0 || opcao > 5)
            printf("\t> Opcao invalida.");

    } while (opcao < 0 || opcao > 5);

    return opcao;
}

void lintiu_executar_menu(LISTA_INT *lista)
{
    int programa_executando = 1;
    int enter;

    while (programa_executando)
    {
        switch(lintiu_menu())
        {
        case 0:
            programa_executando = 0;
            break;

        case 1:
            lintiu_preencher_aleatorio(lista);
            break;

        case 2:
            lintiu_exibir(lista);
            break;

        case 3:
            lintiu_ordenar(lista, lint_heapsort);
            break;

        case 4:
            lintiu_quicksort(lista);
            break;

        case 5:
            lintiu_busca_binaria(lista);
            break;

        default:
            break;
        }

        if (programa_executando)
            ct_scanchar(&enter, "\n\n[PRESSIONE ENTER PARA CONTINUAR]");
    }

    printf("\n>> Menu encerrado.\n");
}
