#include <stdio.h>
#include "ct_input.h"
#include "lista.h"

// liiu: lista de inteiros IU.

void liiu_inserir_valores (LISTA_I *lista)
{
    int elemento;

    if (li_cheia(lista))
        printf("\n>> Lista cheia.");
    else
    {
        printf("\n>> Inserindo Valores:\n");

        for (int i = (lista -> n) + 1; i < TAM_LISTA; i++)
        {
            printf("> Posicao [%d]:", i);
            ct_uscanint(&elemento, "\n\t.. Insira o valor..: ", "\t\t> Valor invalido.");
            li_inserir_pos(lista, elemento, i);
        }
    }
}

void liiu_preencher_aleatorio (LISTA_I *lista)
{
    int valor_inicial, valor_final;

    printf("\n>> Preenchendo com Valores Aleatorios:");

    printf("\n>> Definindo Faixa de Valores:");
    ct_uscanint(&valor_inicial, "\n\t.. Insira o valor inicial..: ", "\t\t> Valor invalido.");
    ct_uscanint(&valor_final, "\t.. Insira o valor final..: ", "\t\t> Valor invalido.\n");

    if (valor_final > valor_inicial)
        li_preencher_aleatorio(lista, valor_inicial, valor_final);
    else
        li_preencher_aleatorio(lista, valor_final, valor_inicial);

    printf("\n>> Lista preenchida!");
}

void liiu_exibir (LISTA_I *lista)
{
    if (li_vazia(lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n>> Exibindo Lista:");

        for (int i = 0; i <= lista -> n; i++)
            printf("\n\t> Elemento %d: %d", i, lista -> valores[i]);
    }
}

void liiu_buscar (LISTA_I *lista, int (*funcao_busca)(LISTA_I *, int, int *))
{
    int elemento, qnt_passos, posicao_buscada;

    if (li_vazia(lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n>> Realizando Busca:");
        ct_uscanint(&elemento, "\n.. Insira o elemento buscado..: ", "\t> Valor invalido.");

        posicao_buscada = funcao_busca(lista, elemento, &qnt_passos);

        if (posicao_buscada == -1)
            printf("\n>> Elemento nao encontrado.");
        else
            printf("\n>> Elemento encontrado na posicao: %d", posicao_buscada);

        printf("\n>> Numero de passos realizados: %d", qnt_passos);
    }
}

void liiu_ordenar (LISTA_I *lista, int (*funcao_ordenacao)(LISTA_I *, int *))
{
    int qnt_passos, status, opcao;
    LISTA_I lista_aux;

    if (li_vazia(lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n>> Ordenando Lista:");

        li_copiar(&lista_aux, lista);
        status = funcao_ordenacao(&lista_aux, &qnt_passos);

        printf("\n>> Lista ordenada com sucesso!");
        printf("\n>> Numero de passos realizados: %d\n", qnt_passos);

        printf("\n>> Lista original:");
        liiu_exibir(lista);

        printf("\n\n>> Lista ordenada:");
        liiu_exibir(&lista_aux);

        printf("\n\n>> Deseja salvar as alteracoes na lista?");
        printf("\n[1] Sim");
        printf("\n[2] Nao");

        do
        {
            ct_uscanint(&opcao, "\n.. Insira a opcao..: ", "\t> Valor invalido.");

            if (opcao < 1 || opcao > 2)
                printf("\t> Opcao invalida.");

        } while (opcao < 1 || opcao > 2);

        if (opcao == 1)
        {
            li_copiar(lista, &lista_aux);
            printf("\n>> Alteracoes salvas!");
        }

        else
            printf("\n>> Alteracoes descartadas!");
    }
}

int liiu_menu ()
{
    int opcao;

    system("cls");

    printf("------------- [MENU - LISTA DE INTEIROS] -------------");
    printf("\n[1] Preencher lista;");
    printf("\n[2] Exibir lista;");
    printf("\n[3] Ordenar por BUBBLE-SORT;");
    printf("\n[4] Ordenar por SELECTION-SORT;");
    printf("\n[5] Realizar busca SEQUENCIAL;");
    printf("\n[6] Realizar busca BINARIA;");
    printf("\n\n[0] Encerrar programa;");
    printf("\n------------------------------------------------------");

    do
    {
        ct_uscanint(&opcao, "\n.. Insira a opcao..: ", "\t> Valor invalido.");

        if (opcao < 0 || opcao > 6)
            printf("\t> Opcao invalida.");

    } while (opcao < 0 || opcao > 6);

    return opcao;
}

void liiu_executar_menu (LISTA_I *lista)
{
    int menu_executando = 1;
    char enter;

    while (menu_executando)
    {
        switch(liiu_menu())
        {

        case 0:
            menu_executando = 0;
            break;

        case 1:
            liiu_preencher_aleatorio(lista);
            break;

        case 2:
            liiu_exibir(lista);
            break;

        case 3:
            liiu_ordenar(lista, li_bubble_sort);
            break;

        case 4:
            liiu_ordenar(lista, li_selection_sort);
            break;

        case 5:
            liiu_buscar(lista, li_buscar_bs);
            break;

        case 6:
            liiu_buscar(lista, li_buscar_bb);
            break;

        default:
            break;
        }

        if (menu_executando)
            ct_scanchar(&enter, "\n\n[PRESSIONE ENTER PARA CONTINUAR]");
    }

    printf("\n>> Programa encerrado.\n");
}
