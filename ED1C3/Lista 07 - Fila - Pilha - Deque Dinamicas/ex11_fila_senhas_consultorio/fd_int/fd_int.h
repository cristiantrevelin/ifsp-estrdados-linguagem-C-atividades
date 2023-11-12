#include <stdio.h>
#include <stdlib.h>

// fdi: fila dinâmica de ints.

typedef struct sFDI_Node
{
    int info;
    struct sFDI_Node *next;

} FDI_NODE;

typedef struct sFDI
{
    FDI_NODE *inicio;
    FDI_NODE *fim;

} FDI;

void fdi_init (FDI *fila)
{
    fila -> inicio = NULL;
    fila -> fim = NULL;
}

FDI_NODE *fdi_makenode ()
{
    return (FDI_NODE *) malloc(sizeof(FDI_NODE));
}

int fdi_vazia (FDI *fila)
{
    if (fila -> inicio == NULL && fila -> fim == NULL)
        return 1;
    return 0;
}

int fdi_enfileirar (FDI *fila, int valor)
{
    FDI_NODE *new_node = fdi_makenode();

    if (new_node == NULL)
        return 1;

    new_node -> info = valor;
    new_node -> next = NULL;

    if (fdi_vazia(fila))
    {
        fila -> fim = new_node;
        fila -> inicio = new_node;
    }
    else
    {
        fila -> fim -> next = new_node;
        fila -> fim = new_node;
    }

    return 0;
}

int fdi_desenfileirar (FDI *fila)
{
    int valor;
    FDI_NODE *aux_node;

    if (fdi_vazia(fila))
        return -1;

    aux_node = fila -> inicio;
    valor = aux_node -> info;

    fila -> inicio = aux_node -> next;
    free(aux_node);

    if (fila -> inicio == NULL)
        fila -> fim = NULL;

    return valor;
}

int fdi_getfim (FDI *fila)
{
    if (fdi_vazia(fila))
        return -1;
    return fila -> fim -> info;
}
