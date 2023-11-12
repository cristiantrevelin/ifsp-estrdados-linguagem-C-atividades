#include <stdio.h>
#include <time.h>
#define TAM_LISTA 150

typedef struct sLista_Int
{
    int valores[TAM_LISTA];
    int n;

} LISTA_INT;

void lint_init (LISTA_INT *lista)
{
    lista -> n = -1;
}

int lint_vazia (LISTA_INT *lista)
{
    if (lista -> n == -1)
        return 1;
    return 0;
}

int lint_cheia (LISTA_INT *lista)
{
    if (lista -> n == TAM_LISTA - 1)
        return 1;
    return 0;
}

int lint_tamanho (LISTA_INT *lista)
{
    return lista -> n + 1;
}

int lint_inserir_pos (LISTA_INT *lista, int elemento, int pos)
{
    if (lint_cheia(lista) || pos > lista -> n + 1)
        return 1;

    for (int i = lista -> n + 1; i > pos; i--)
        lista -> valores[i] = lista -> valores[i - 1];

    lista -> valores[pos] = elemento;
    (lista -> n)++;

    return 0;
}

void lint_preencher_aleatorio (LISTA_INT *lista, int valor_inicial, int valor_final)
{
    int elemento, faixa_valores;
    time_t t = time(NULL);

    srand(t);
    faixa_valores = valor_final - valor_inicial + 1;

    lint_init(lista);

    for (int i = 0; i < TAM_LISTA; i++)
    {
        elemento = valor_inicial + rand() % faixa_valores;
        lint_inserir_pos(lista, elemento, i);
    }
}

void lint_copiar (LISTA_INT *lista_origem, LISTA_INT *lista_copia)
{
    int i;

    lint_init(lista_copia);

    for (i = 0; i < lint_tamanho(lista_origem); i++)
        lint_inserir_pos(lista_copia, lista_origem -> valores[i], lint_tamanho(lista_copia));

}

void lint_heapify (LISTA_INT *lista, int fim, int *qnt_passos)
{
    int raiz_atual, pos_maior, valor_aux;
    int passos = 0;

    // Obtendo raiz da ultima subarvore.

    raiz_atual = (fim - 2) / 2;

    if (fim > 1)
        if ((fim + 1) % 2 == 0)
            raiz_atual += 1;


    // Percorrendo a arvore, do fim para o início, e realizando
    // as trocas de valores.

    while (raiz_atual > -1)
    {

        // Obtendo maior valor entre a raíz da subárvore e seus filhos.

        if (2 * raiz_atual + 2 <= fim)
        {
            if (lista -> valores[2 * raiz_atual + 1] > lista -> valores[2 * raiz_atual + 2])
                pos_maior = 2 * raiz_atual + 1;
            else
                pos_maior = 2 * raiz_atual + 2;
        }
        else
            pos_maior = 2 * raiz_atual + 1;


        // Realizando a troca.

        if (lista -> valores[raiz_atual] < lista -> valores[pos_maior])
        {
            valor_aux = lista -> valores[raiz_atual];
            lista -> valores[raiz_atual] = lista -> valores[pos_maior];
            lista -> valores[pos_maior] = valor_aux;
        }

        raiz_atual--;
        passos++;
    }

    if (qnt_passos != NULL)
        *qnt_passos = passos;
}

int lint_heapsort (LISTA_INT *lista, int *qnt_passos)
{
    int fim_lista = lista -> n;
    int valor_aux, passos, total_passos = 0;

    if (lint_tamanho(lista) < 2)
        return 1;

    while (fim_lista > 0)
    {
        lint_heapify(lista, fim_lista, &passos);
        total_passos += passos;

        valor_aux = lista -> valores[0];
        lista -> valores[0] = lista -> valores[fim_lista];
        lista -> valores[fim_lista] = valor_aux;

        fim_lista--;
    }

    if (qnt_passos != NULL)
        *qnt_passos = total_passos;

    return 0;
}

int lint_plomuto (LISTA_INT *lista, int inicio, int fim, int *qnt_passos)
{
    int pivot, i, passos = 0;
    int valor_aux, pos_menor;

    int maior_encontrado = 0;

    if (fim - inicio == 0)
        return -1;

    pos_menor = fim + 1;


    // Particionamento de LOMUTO:

    pivot = lista -> valores[inicio];

    for (i = inicio + 1; i <= fim; i++)
    {
        if (lista -> valores[i] <= pivot)
        {
            if (maior_encontrado)
            {
                valor_aux = lista -> valores[i];
                lista -> valores[i] = lista -> valores[pos_menor];
                lista -> valores[pos_menor] = valor_aux;

                pos_menor++;
            }
        }
        else if (!maior_encontrado)
        {
            maior_encontrado = 1;
            pos_menor = i;
        }

        passos++;
    }

    lista -> valores[inicio] = lista -> valores[pos_menor - 1];
    lista -> valores[pos_menor - 1] = pivot;

    passos++;

    if (qnt_passos != NULL)
        *qnt_passos += passos;

    return pos_menor - 1;
}

int lint_quicksort (LISTA_INT *lista, int inicio, int fim, int *qnt_passos)
{
    int pos_pivot;

    pos_pivot = lint_plomuto(lista, inicio, fim, qnt_passos);

    if (pos_pivot != -1)
    {
        if (pos_pivot != inicio)
            lint_quicksort(lista, inicio, pos_pivot - 1, qnt_passos);

        if (pos_pivot != fim)
            lint_quicksort(lista, pos_pivot + 1, fim, qnt_passos);
    }
}

int lint_busca_binaria (LISTA_INT *lista, int inicio, int fim, int chave, int *qnt_passos)
{
    int deslocamento_meio, pos_meio, pos_chave = -1;

    deslocamento_meio = (fim - inicio) / 2;
    pos_meio = inicio + deslocamento_meio;

    if (lista -> valores[pos_meio] == chave)
        pos_chave = pos_meio;
    else
    {
        if (fim - inicio > 0)
        {
            if (chave < lista -> valores[pos_meio])
                pos_chave = lint_busca_binaria(lista, inicio, pos_meio - 1, chave, qnt_passos);
            else
                pos_chave = lint_busca_binaria(lista, pos_meio + 1, fim, chave, qnt_passos);
        }
    }

    if (qnt_passos != NULL)
        (*qnt_passos)++;

    return pos_chave;
}
