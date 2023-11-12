#include <stdlib.h>
#include <time.h>
#include "ct_input.h"

#define TAM_LISTA 15

// li: lista de inteiros.

typedef struct sLista_I
{
    int valores[TAM_LISTA];
    int n;

} LISTA_I;

void li_init (LISTA_I *lista)
{
    lista -> n = -1;
}

int li_vazia (LISTA_I *lista)
{
    if (lista -> n == -1)
        return 1;
    return 0;
}

int li_cheia (LISTA_I *lista)
{
    if (lista -> n == TAM_LISTA - 1)
        return 1;
    return 0;
}

int li_largura (LISTA_I *lista)
{
    return lista -> n + 1;
}

int li_inserir_pos (LISTA_I *lista, int elemento, int pos)
{
    if (li_cheia(lista) || pos > lista -> n + 1)
        return 1;

    for (int i = lista -> n + 1; i > pos; i--)
        lista -> valores[i] = lista -> valores[i - 1];

    lista -> valores[pos] = elemento;
    (lista -> n)++;

    return 0;
}

void li_preencher_aleatorio (LISTA_I *lista, int valor_inicial, int valor_final)
{
    int elemento, faixa_valores;
    time_t t = time(NULL);

    srand(t);
    faixa_valores = valor_final - valor_inicial + 1;

    li_init(lista);

    for (int i = 0; i < TAM_LISTA; i++)
    {
        elemento = valor_inicial + rand() % faixa_valores;
        li_inserir_pos(lista, elemento, (lista -> n) + 1);
    }
}

int li_bubble_sort (LISTA_I *lista, int *num_passos)
{
    int tam_lista, valor_aux, passos = 0;

    tam_lista = li_largura(lista);

    if (tam_lista < 2)
        return 1;

    for (int i = 0; i < tam_lista - 1; i++)
    {
        for (int j = 0; j < tam_lista - 1; j++)
        {
            if (lista -> valores[j] > lista -> valores[j+1])
            {
                valor_aux = lista -> valores[j];

                lista -> valores[j] = lista -> valores[j+1];
                lista -> valores[j+1] = valor_aux;

                passos++;
            }
        }
    }

    if (num_passos != NULL)
        *num_passos = passos;

    return 0;
}

int li_selection_sort (LISTA_I *lista, int *num_passos)
{
    int tam_lista, valor_menor, pos_menor, passos = 0;

    tam_lista = li_largura(lista);

    if (tam_lista < 2)
        return 1;

    for (int i = 0; i < tam_lista - 1; i++)
    {
        valor_menor = lista -> valores[i];
        pos_menor = i;

        for (int j = i; j < tam_lista; j++)
        {
            if (lista -> valores[j] < valor_menor)
            {
                valor_menor = lista -> valores[j];
                pos_menor = j;

                passos++;
            }
        }

        if (pos_menor != i)
        {
            lista -> valores[pos_menor] = lista -> valores[i];
            lista -> valores[i] = valor_menor;

            passos++;
        }
    }

    if (num_passos != NULL)
        *num_passos = passos;

    return 0;
}

void li_copiar (LISTA_I *lista, LISTA_I *lista_copiada)
{
    int tam_lista;

    li_init(lista);
    tam_lista = li_largura(lista_copiada);

    for (int i = 0; i < tam_lista; i++)
        li_inserir_pos(lista, lista_copiada -> valores[i], i);
}

int li_buscar_bs (LISTA_I *lista, int valor_alvo, int *num_passos)
{
    // bs: busca sequencial.

    int posicao = -1;
    int i = 0;
    int alvo_encontrado = 0;

    if (!li_vazia(lista))
    {
        while (lista -> valores[i] <= valor_alvo && !alvo_encontrado)
        {
            if (lista -> valores[i] == valor_alvo)
            {
                posicao = i;
                alvo_encontrado = 1;
            }

            i++;
        }
    }

    if (num_passos != NULL)
        *num_passos = i;

    return posicao;
}

int li_buscar_bb (LISTA_I *lista, int valor_alvo, int *num_passos)
{
    // bb: busca binária.

    int posicao = -1;
    int passos = 0;
    int alvo_encontrado = 0, ultimo_caso = 0;
    int i_taxd;     // i_taxd: taxa de deslocamento do indice.
    int i_inicial, i_final, i_medio;

    i_inicial = 0;
    i_final = lista -> n;

    if (!li_vazia(lista))
    {
        while (!alvo_encontrado && i_final - i_inicial != 1)
        {
            i_taxd = (i_final - i_inicial + 1) / 2;
            i_medio = i_inicial + i_taxd;

            if (valor_alvo > lista -> valores[i_medio])
                i_inicial = i_medio;
            else if (valor_alvo < lista -> valores[i_medio])
                i_final = i_medio;
            else
            {
                posicao = i_medio;
                alvo_encontrado = 1;
            }

            passos++;
        }

        if (i_final - i_inicial == 1)
        {
            if (valor_alvo == lista -> valores[i_inicial])
                posicao = i_inicial;
            else if (valor_alvo == lista -> valores[i_final])
                posicao = i_final;

            passos++;
        }
    }

    if (num_passos != NULL)
        *num_passos = passos;

    return posicao;
}
