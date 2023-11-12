#include <stdio.h>
#define TAM_MAX 15

typedef struct int_stack
{
    int valores[TAM_MAX];
    int topo;

} INT_STACK;

void pilha_int_inicializar (INT_STACK *Pilha)
{
    Pilha -> topo = -1;
}

int pilha_int_cheia (INT_STACK *Pilha)
{
    if (Pilha -> topo == TAM_MAX - 1)
        return 1;
    return 0;
}

int pilha_int_vazia (INT_STACK *Pilha)
{
    if (Pilha -> topo == -1)
        return 1;
    return 0;
}

int pilha_int_push (INT_STACK *Pilha, int elemento)
{
    if (pilha_int_cheia(Pilha))
    {
        printf("\n   >> Erro - Pilha cheia.");
        return 1;
    }

    Pilha -> topo++;
    Pilha -> valores[Pilha -> topo] = elemento;

    return 0;
}

int pilha_int_pop (INT_STACK *Pilha)
{
    if (pilha_int_vazia(Pilha))
    {
        printf("\n   >> Erro - Pilha vazia.");
        return 1;
    }

    Pilha -> topo--;

    return 0;
}

int *pilha_int_pop_return (INT_STACK *Pilha)
{
    int *pont_elemento = NULL;

    if (pilha_int_vazia(Pilha))
        printf("\n   >> Erro - Pilha vazia.");
    else
    {
        pont_elemento = Pilha -> valores + Pilha -> topo;
        Pilha -> topo--;
    }

    return pont_elemento;
}

void pilha_int_preencher_par_impar (INT_STACK *Pilha)
{
    int elemento, i;

    pilha_int_inicializar(Pilha);
    printf("\n>> Preenchendo a Pilha:");

    for (i = 0; i < TAM_MAX; i++)
    {
        printf("\n   .. Insira o %do elemento..: ", i);
        scanf("%d", &elemento);

        if (elemento % 2 == 0)
        {
            pilha_int_push(Pilha, elemento);
            printf("      >> Elemento empilhado!");
        }
        else
        {
            if (pilha_int_pop(Pilha) == 0)
                printf("      >> Elemento desempilhado!");
        }
    }
}

int pilha_int_esvaziar_apresentando (INT_STACK *Pilha)
{
    int i, auxiliar_topo, *elemento_desempilhado;

    auxiliar_topo = Pilha -> topo;

    if (pilha_int_vazia(Pilha))
        return 1;

    printf("\n>> Esvaziando a Pilha:");

    for (i = 0; i <= auxiliar_topo; i++)
    {
        elemento_desempilhado = pilha_int_pop_return(Pilha);
        printf("\n   > Elemento Desempilhado: %d", *elemento_desempilhado);
    }

    return 0;
}

int pilha_int_apresentar (INT_STACK *Pilha)
{
    int i;

    if (pilha_int_vazia(Pilha))
    {
        printf("\n   >> Erro - Pilha Vazia.");
        return 1;
    }

    printf("\n>> Apresentando Pilha:");

    for (i = Pilha -> topo; i >= 0; i--)
        printf("\n   > Elemento [%d]: %d", i, Pilha -> valores[i]);

    return 0;
}
