#include <stdlib.h>
#include <time.h>
#define TAM_LISTA 15

// lc: lista de char.

typedef struct sLista_Char
{
    char valores[TAM_LISTA];
    int n;

} LISTA_C;

void lc_init(LISTA_C *lista)
{
    lista -> n = -1;
}

int lc_tamanho(LISTA_C *lista)
{
    return lista -> n + 1;
}

int lc_vazia(LISTA_C *lista)
{
    if (lista -> n == -1)
        return 1;
    return 0;
}

int lc_cheia(LISTA_C *lista)
{
    if (lista -> n == TAM_LISTA - 1)
        return 1;
    return 0;
}

int lc_inserir_fim(LISTA_C *lista, char elemento)
{
    if (lc_cheia(lista))
        return 1;

    (lista -> n)++;
    lista -> valores[lista -> n] = elemento;

    return 0;
}

void lc_preencher_aleatorio(LISTA_C *lista, char valor_inicial, char valor_final)
{
    int i;
    char elemento;
    time_t t;

    t = time(NULL);
    srand(t);

    lc_init(lista);

    for (i = 0; i < TAM_LISTA; i++)
    {
        elemento = valor_inicial + rand() % (valor_final - valor_inicial + 1);
        lc_inserir_fim(lista, elemento);
    }
}

int lc_copiar(LISTA_C *lista_original, LISTA_C *lista_copia)
{
    if (lc_vazia(lista_original))
        return 1;

    lc_init(lista_copia);

    for (int i = 0; i < lc_tamanho(lista_original); i++)
        lc_inserir_fim(lista_copia, lista_original -> valores[i]);

    return 0;
}

int lc_insertion_sort(LISTA_C *lista, int *qnt_passos)
{
    int tam_lista, j, valor_aux, passos = 0;
    int valor_ordenado; // boolean

    tam_lista = lc_tamanho(lista);

    if (tam_lista < 2)
        return 1;

    for (int i = 1; i < tam_lista; i++)
    {
        j = i;
        valor_ordenado = 0;

        while (j >= 0 && !valor_ordenado)
        {
            if (lista -> valores[j] < lista -> valores[j-1])
            {
                valor_aux = lista -> valores[j-1];
                lista -> valores[j-1] = lista -> valores[j];
                lista -> valores[j] = valor_aux;
            }
            else
                valor_ordenado = 1;

            j--;
            passos++;
        }
    }

    if (qnt_passos != NULL)
        *qnt_passos = passos;

    return 0;
}

int lc_shell_sort(LISTA_C *lista, int *qnt_passos)
{
    int i, j, h = 0;
    int tam_lista, passos = 0;
    int valor_aux;

    tam_lista = lc_tamanho(lista);

    if (tam_lista < 2)
        return 1;

    while (h < tam_lista)
        h = h * 3 + 1;

    while (h > 0)
    {
        i = h;

        while (i < tam_lista)
        {
            valor_aux = lista -> valores[i];
            j = i;

            while (j >= h && valor_aux < lista -> valores[j - h])
            {
                lista -> valores[j] = lista -> valores[j - h];
                j = j - h;
            }

            lista -> valores[j] = valor_aux;

            i++;
            passos++;
        }

        h = (h - 1) / 3;
    }

    if (qnt_passos != NULL)
        *qnt_passos = passos;

    return 0;
}
