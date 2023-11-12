#include <stdio.h>
#include "ct_headers/ct_io.h"
#include "lista.h"
#define TF 50

int menu ()
{
    int opcao;

    system("cls");

    printf("------------ [MENU - LISTA] ------------");
    printf("\n[1] Preencher com Valores Aleatorios;");
    printf("\n[2] Exibir Lista;");
    printf("\n[3] Realizar Busca Exaustiva;");
    printf("\n[4] Realizar Busca Sequencial;");
    printf("\n[5] Realizar Busca Binaria;");
    printf("\n[0] Encerrar Programa;");
    printf("\n----------------------------------------");

    do
    {
        ct_uscanint(&opcao, "\n.. Insira a opcao..: ", "\t> Valor invalido.");

        if (opcao < 0 || opcao > 5)
            printf("\t> Opcao invalida.");

    } while (opcao < 0 || opcao > 5);
}

void menu_preencher_aleatorio (LISTA_O *lista)
{
    int valor_inicial, valor_final;

    printf("\n>> Preenchendo Lista com Valores Aleatorios:");
    printf("\n>> Definindo Faixa de Valores...");
    ct_uscanint(&valor_inicial, "\n\t.. Insira o valor inicial..: ", "\t> Valor Invalido.");
    ct_uscanint(&valor_final, "\t.. Insira o valor final..: ", "\t> Valor Invalido.\n");

    lo_preencher_aleatorio(lista, valor_inicial, valor_final);
    printf("\n>> Lista preenchida com sucesso!");
}

void menu_buscar (LISTA_O *lista, int (*funcao_busca)(LISTA_O *, int, int *))
{
    int valor_alvo, posicao, num_passos;

    if (lo_vazia(lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n>> Realizando Busca:");
        ct_uscanint(&valor_alvo, "\n\t.. Insira o valor buscado..: ", "\t> Valor Invalido.");

        posicao = funcao_busca(lista, valor_alvo, &num_passos);

        if (posicao == -1)
            printf("\n>> Valor nao encontrado.");
        else
            printf("\n>> Valor encontrado na posicao: %d", posicao);

        printf("\n>> Numero de passos realizados: %d", num_passos);
    }
}

void executar_menu (LISTA_O *lista)
{
    int menu_executando = 1;
    char enter_buffer;

    do
    {
        switch (menu())
        {
        case 0:
            menu_executando = 0;
            break;

        case 1:
            menu_preencher_aleatorio(lista);
            break;

        case 2:
            lo_exibir(lista);
            break;

        case 3:
            menu_buscar(lista, &lo_buscar_be);
            break;

        case 4:
            menu_buscar(lista, &lo_buscar_bs);
            break;

        case 5:
            menu_buscar(lista, &lo_buscar_bb);
            break;

        default:
            break;
        }

        if (menu_executando)
            ct_scanchar(&enter_buffer, "\n\n[PRESSIONE ENTER PARA CONTINUAR]");

    } while (menu_executando);

    printf("\n>> Menu Encerrado.\n");
}

void main ()
{
    LISTA_O lista;
    lo_init(&lista);
    executar_menu(&lista);
}
