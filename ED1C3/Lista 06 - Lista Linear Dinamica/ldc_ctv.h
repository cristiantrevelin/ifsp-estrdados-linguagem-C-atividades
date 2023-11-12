#include <stdio.h>
#include <stdlib.h>

#include "ct_io.h"
#include "ct_string.h"

#define TAM_CANAL 100

// ldcctv: lista dinamica circular de canais de TV.

typedef char * CANAL;

typedef struct sCTV_Node
{
    CANAL info;
    struct sCTV_Node *next;

} CTV_NODE;

void ldcctv_init (CTV_NODE **ptr_lista)
{
    *ptr_lista = NULL;
}

CTV_NODE *ldcctv_makenode ()
{
    return (CTV_NODE *) malloc(sizeof(CTV_NODE));
}

int ldcctv_vazia (CTV_NODE *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

int ldcctv_addfim (CTV_NODE **ptr_lista, CANAL canal)
{
    CTV_NODE *aux;
    CTV_NODE *new_node;

    aux = *ptr_lista;
    new_node = ldcctv_makenode();

    if (new_node == NULL)
        return 1;

    new_node -> info = canal;

    if (ldcctv_vazia(aux))
    {
        *ptr_lista = new_node;
        new_node -> next = new_node;
    }
    else
    {
        while (aux -> next != *ptr_lista)
            aux = aux -> next;

        aux -> next = new_node;
        new_node -> next = *ptr_lista;
    }

    return 0;
}

CTV_NODE *ldcctv_getcanal (CTV_NODE *lista, CANAL canal)
{
    CTV_NODE *aux = lista;

    if (!ldcctv_vazia(aux))
    {
        do
        {
            if (ct_equals(aux -> info, canal))
                return aux;

            aux = aux -> next;

        } while (aux != lista);
    }

    return NULL;
}

void ldcctv_apagar_canal (CANAL canal)
{
    free(canal);
}

int ldcctv_remover_canal (CTV_NODE **ptr_lista, CANAL canal)
{
    CTV_NODE *aux = *ptr_lista;
    CTV_NODE *target;

    target = ldcctv_getcanal(aux, canal);

    if (target == NULL)
        return 1;
    else
    {
        if (target -> next == target)
            *ptr_lista = NULL;
        else
        {
            while (aux -> next != target)
                aux = aux -> next;

            aux -> next = target -> next;

            if (*ptr_lista == target)
                *ptr_lista = target -> next;
        }

        ldcctv_apagar_canal(target -> info);
        free(target);
    }

    return 0;
}

void ldcctv_uaddfim (CTV_NODE **ptr_lista)
{
    CANAL canal;

    printf("\n[CADASTRAR CANAL]");
    canal = ct_getline(TAM_CANAL, "\n.. Insira o canal..: ");

    if (canal == NULL)
        printf("\n>> Erro ao cadastrar o canal.");
    else
    {
        if (ldcctv_addfim(ptr_lista, canal) == 0)
            printf("\n>> Canal adicionado com sucesso!");
        else
            printf("\n>> Nao foi possivel adicionar o canal.");
    }
}

void ldcctv_uremover_canal (CTV_NODE **ptr_lista)
{
    CANAL canal;

    printf("\n[REMOVER CANAL]");
    canal = ct_getline(TAM_CANAL, "\n.. Insira o canal..: ");

    if (canal == NULL)
        printf("\n>> Erro ao ler o canal.");
    else
    {
        if (ldcctv_remover_canal(ptr_lista, canal) == 0)
            printf("\n>> Canal removido com sucesso!");
        else
            printf("\n>> Canal nao encontrado.");

        ldcctv_apagar_canal(canal);
    }
}

void ldcctv_exibir_canal (CANAL canal)
{
    printf("%s", canal);
}

int ldcctv_menu_simulacao ()
{
    int opcao;

    printf("\n----------------------------------");

    printf("\n\n[1] Proximo canal;");
    printf("\n[0] Encerrar simulacao.");
    printf("\n----------------------------------");

    do
    {
        ct_uscanint(&opcao, "\n.. Insira a opcao..: ", "\t>> Opcao invalida.");

        if (opcao < 0 || opcao > 1)
            printf("\t>> Opcao invalida.");

    } while (opcao < 0 || opcao > 1);

    return opcao;
}

void ldcctv_simular_canais (CTV_NODE *lista)
{
    int opcao, simulando = 1;
    CTV_NODE *aux = lista;

    if (ldcctv_vazia(aux))
        printf("\n>> Nao ha canais cadastrados.");
    else
    {
        do
        {
            system("cls");

            printf("-------- [SIMULACAO - TV] --------");
            printf("\n>> CANAL ATUAL: ");
            ldcctv_exibir_canal(aux -> info);

            switch (ldcctv_menu_simulacao())
            {
            case 0:
                simulando = 0;
                break;

            case 1:
                aux = aux -> next;
                break;

            default:
                break;
            }

        } while (simulando);

        printf("\n>> Simulacao encerrada.");
    }
}
