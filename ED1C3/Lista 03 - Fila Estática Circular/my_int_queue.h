#include <stdio.h>
#include "my_int_stack.h"
#define TAM_MAX 21

typedef struct int_queue
{
    int valores[TAM_MAX];
    int inicio;
    int fim;

} INT_QUEUE;

void fila_int_inicializar (INT_QUEUE *Fila)
{
    Fila -> inicio = TAM_MAX - 1;
    Fila -> fim = TAM_MAX - 1;
}

int fila_int_cheia (INT_QUEUE *Fila)
{
    int fim = Fila -> fim;

    if (fim == TAM_MAX - 1)
        fim = 0;
    else
        fim++;

    if (fim == Fila -> inicio)
        return 1;
    return 0;
}

int fila_int_vazia (INT_QUEUE *Fila)
{
    if (Fila -> inicio == Fila -> fim)
        return 1;
    return 0;
}

int fila_int_enfileirar (INT_QUEUE *Fila, int elemento)
{
    if (fila_int_cheia(Fila))
    {
        printf("\n>> Erro - Fila cheia.");
        return 1;
    }

    if (Fila -> fim == TAM_MAX - 1)
        Fila -> fim = 0;
    else
        Fila -> fim++;

    Fila -> valores[Fila -> fim] = elemento;
    return 0;
}

int *fila_int_desenfileirar (INT_QUEUE *Fila)
{
    int *auxiliar = NULL;

    if (fila_int_vazia(Fila))
        printf("\n>> Erro - Fila vazia.");
    else
    {
        if (Fila -> inicio == TAM_MAX - 1)
            Fila -> inicio = 0;
        else
            Fila -> inicio++;

        auxiliar = Fila -> valores + Fila -> inicio;
    }

    return auxiliar;
}

void fila_int_apresentar (INT_QUEUE Fila)
{
    int *elemento, contador = 1;

    if (fila_int_vazia(&Fila))
        printf("\n>> Fila vazia.");
    else
    {
        printf("\n>> Apresentando Fila:");

        while (!fila_int_vazia(&Fila))
        {
            elemento = fila_int_desenfileirar(&Fila);
            printf("\n   > %do elemento: %d", contador, *elemento);
            contador++;
        }
    }
}

int fila_int_calcular_comprimento (INT_QUEUE Fila)
{
    int comprimento = 0;

    while (!fila_int_vazia(&Fila))
    {
        fila_int_desenfileirar(&Fila);
        comprimento++;
    }

    return comprimento;
}

int fila_int_inverter (INT_QUEUE *Fila)
{
    int *elemento;

    INT_STACK Pilha;
    pilha_int_inicializar(&Pilha);

    if (fila_int_vazia(Fila))
    {
        printf("\n>> Erro - Fila vazia.");
        return 1;
    }

    while (!fila_int_vazia(Fila))
    {
        elemento = fila_int_desenfileirar(Fila);
        pilha_int_push(&Pilha, *elemento);
    }

    while (!pilha_int_vazia(&Pilha))
    {
        elemento = pilha_int_pop_return(&Pilha);
        fila_int_enfileirar(Fila, *elemento);
    }

    return 0;
}

int fila_int_esvaziar (INT_QUEUE *Fila)
{
    // Esvazia a fila dada e retorna a quantidade de elementos removidos.

    int contador_elementos = 0;

    while (!fila_int_vazia(Fila))
    {
        fila_int_desenfileirar(Fila);
        contador_elementos++;
    }

    return contador_elementos;
}

int fila_int_maior_que (INT_QUEUE Fila_1, INT_QUEUE Fila_2)
{
    // Compara a quantidade de elementos de Fila_1 com Fila_2 e
    // retorna 1 caso Fila_1 tenha mais elementos. Do contrário,
    // retorna 0.

    int contador_fila1, contador_fila2;

    contador_fila1 = fila_int_esvaziar(&Fila_1);
    contador_fila2 = fila_int_esvaziar(&Fila_2);

    if (contador_fila1 > contador_fila2)
        return 1;
    return 0;
}
