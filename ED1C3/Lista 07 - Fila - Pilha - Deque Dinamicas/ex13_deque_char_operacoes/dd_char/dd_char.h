#include <stdio.h>
#include <stdlib.h>

// ddc: deque dinâmica de chars.

typedef struct sDDC_Node
{
    char info;
    struct sDDC_Node *next;
    struct sDDC_Node *previous;

} DDC_NODE;

typedef struct sDDC
{
    DDC_NODE *inicio;
    DDC_NODE *fim;

} DDC;

void ddc_init (DDC *Deque)
{
    Deque -> inicio = NULL;
    Deque -> fim = NULL;
}

DDC_NODE *ddc_makenode ()
{
    return (DDC_NODE *) malloc(sizeof(DDC_NODE));
}

int ddc_vazia (DDC *Deque)
{
    if (Deque -> inicio == NULL && Deque -> fim == NULL)
        return 1;
    return 0;
}

int ddc_inserir_inicio (DDC *Deque, char elemento)
{
    DDC_NODE *new_node = ddc_makenode();

    if (new_node == NULL)
        return 1;   // Erro na alocação do node.

    new_node -> info = elemento;
    new_node -> previous = NULL;

    if (ddc_vazia(Deque))
    {
        new_node -> next = NULL;

        Deque -> inicio = new_node;
        Deque -> fim = new_node;
    }
    else
    {
        new_node -> next = Deque -> inicio;
        Deque -> inicio = new_node;
    }

    return 0;
}

int ddc_inserir_fim (DDC *Deque, char elemento)
{
    DDC_NODE *new_node = ddc_makenode();

    if (new_node == NULL)
        return 1;

    new_node -> info = elemento;
    new_node -> next = NULL;

    if (ddc_vazia(Deque))
    {
        new_node -> previous = NULL;

        Deque -> fim = new_node;
        Deque -> inicio = new_node;
    }
    else
    {
        Deque -> fim -> next = new_node;
        new_node -> previous = Deque -> fim;
        Deque -> fim = new_node;
    }

    return 0;
}

char ddc_remover_inicio (DDC *Deque)
{
    DDC_NODE *aux_node;
    char elemento_removido;

    if (ddc_vazia(Deque))
        return '\0';

    aux_node = Deque -> inicio;
    Deque -> inicio = Deque -> inicio -> next;

    if (Deque -> inicio == NULL)
        Deque -> fim = NULL;
    else
        Deque -> inicio -> previous = NULL;

    elemento_removido = aux_node -> info;
    free(aux_node);

    return elemento_removido;
}

char ddc_remover_fim (DDC *Deque)
{
    DDC_NODE *aux_node;
    char elemento_removido;

    if (ddc_vazia(Deque))
        return '\0';

    aux_node = Deque -> fim;
    Deque -> fim = Deque -> fim -> previous;

    if (Deque -> fim == NULL)
        Deque -> inicio = NULL;
    else
        Deque -> fim -> next = NULL;

    elemento_removido = aux_node -> info;
    free(aux_node);

    return elemento_removido;
}

int ddc_transferir (DDC *Deque1, DDC *Deque2)
{
    while (!ddc_vazia(Deque2))
    {
        if (ddc_inserir_inicio(Deque1, ddc_remover_inicio(Deque2)) == 1)
            return 1;
    }

    return 0;
}
