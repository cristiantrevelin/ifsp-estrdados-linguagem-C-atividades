#include <stdio.h>
#include <stdlib.h>

// pdf: pilha dinâmica de floats.

typedef struct sPDF_Node
{
    float info;
    struct sPDF_Node *next;

} PDF_NODE;

void pdf_init (PDF_NODE **ptr_pilha)
{
    *ptr_pilha = NULL;
}

int pdf_vazia (PDF_NODE *pilha)
{
    if (pilha == NULL)
        return 1;
    return 0;
}

PDF_NODE *pdf_makenode ()
{
    return (PDF_NODE *) malloc(sizeof(PDF_NODE));
}

int pdf_push (PDF_NODE **ptr_pilha, float valor)
{
    PDF_NODE *new_node = pdf_makenode();

    if (new_node == NULL)
        return 1;

    new_node -> info = valor;

    if (pdf_vazia(*ptr_pilha))
    {
        new_node -> next = NULL;
        *ptr_pilha = new_node;
    }
    else
    {
        new_node -> next = *ptr_pilha;
        *ptr_pilha = new_node;
    }

    return 0;
}

float pdf_pop (PDF_NODE **ptr_pilha)
{
    PDF_NODE *aux_node = *ptr_pilha;
    float info = 0;

    if (!pdf_vazia(aux_node))
    {
        info = aux_node -> info;

        *ptr_pilha = aux_node -> next;
        free(aux_node);
    }

    return info;
}

int pdf_transferir (PDF_NODE **ptr_pilha1, PDF_NODE **ptr_pilha2)
{
    // Transfere o conteúdo empilhado da pilha2 para a pilha1.

    if (pdf_vazia(*ptr_pilha2))
        return 1;

    while (!pdf_vazia(*ptr_pilha2))
    {
        if (pdf_push(ptr_pilha1, pdf_pop(ptr_pilha2)) == 1)
            return 1;
    }

    return 0;
}
