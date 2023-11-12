#include <stdio.h>
#include <time.h>
#define TAM_LISTA 100

typedef struct sLista_O
{
    int valores[TAM_LISTA];
    int n;

} LISTA_O;

void lo_init (LISTA_O *lista)
{
    lista -> n = -1;
}

int lo_vazia (LISTA_O *lista)
{
    if (lista -> n == -1)
        return 1;
    return 0;
}

int lo_cheia (LISTA_O *lista)
{
    if (lista -> n == TAM_LISTA - 1)
        return 1;
    return 0;
}

int lo_inserir_pos (LISTA_O *lista, int elemento, int pos)
{
    if (lo_cheia(lista) || pos > lista -> n + 1)
        return 1;

    for (int i = lista -> n + 1; i > pos; i--)
        lista -> valores[i] = lista -> valores[i - 1];

    lista -> valores[pos] = elemento;
    (lista -> n)++;

    return 0;
}

int lo_inserir_o (LISTA_O *lista, int elemento)
{
    if (lo_cheia(lista))
        return 1;

    if (lo_vazia(lista))
    {
        (lista -> n)++;
        lista -> valores[lista -> n] = elemento;
    }
    else
    {
        for (int i = 0; i <= lista -> n; i++)
        {
            if (lista -> valores[i] > elemento)
            {
                lo_inserir_pos(lista, elemento, i);
                return 0;
            }
        }

        lo_inserir_pos(lista, elemento, lista -> n + 1);
    }

    return 0;
}

void lo_preencher_aleatorio (LISTA_O *lista, int valor_inicial, int valor_final)
{
    int elemento, faixa_valores;
    time_t t = time(NULL);

    srand(t);
    faixa_valores = valor_final - valor_inicial + 1;

    lo_init(lista);

    for (int i = 0; i < TAM_LISTA; i++)
    {
        elemento = valor_inicial + rand() % faixa_valores;
        lo_inserir_o(lista, elemento);
    }
}

void lo_exibir (LISTA_O *lista)
{
    if (lo_vazia(lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n>> Exibindo Lista:");

        for (int i = 0; i <= lista -> n; i++)
            printf("\n\t> Elemento %d: %d", i, lista -> valores[i]);
    }
}

int lo_buscar_be (LISTA_O *lista, int valor_alvo, int *num_passos)
{
    // be: busca exaustiva.

    int posicao = -1;
    int i = 0;
    int alvo_encontrado = 0;     // boolean.

    if (!lo_vazia(lista))
    {
        while (i <= lista -> n && !alvo_encontrado)
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

int lo_buscar_bs (LISTA_O *lista, int valor_alvo, int *num_passos)
{
    // bs: busca sequencial.

    int posicao = -1;
    int i = 0;
    int alvo_encontrado = 0;

    while (lista -> valores[i] <= valor_alvo && !alvo_encontrado)
    {
        if (lista -> valores[i] == valor_alvo)
        {
            posicao = i;
            alvo_encontrado = 1;
        }

        i++;
    }

    if (num_passos != NULL)
        *num_passos = i;

    return posicao;
}

int lo_buscar_bb (LISTA_O *lista, int valor_alvo, int *num_passos)
{
    // bb: busca binária.

    int posicao = -1;
    int passos = 0;
    int alvo_encontrado = 0, ultimo_caso = 0;
    int i_taxd;     // i_taxd: taxa de deslocamento do indice.
    int i_inicial, i_final, i_medio;

    i_inicial = 0;
    i_final = lista -> n;

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

    if (num_passos != NULL)
        *num_passos = passos;

    return posicao;
}
