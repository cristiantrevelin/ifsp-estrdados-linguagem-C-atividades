#include <stdio.h>
#include <stdlib.h>
#include "ct_string.h"
#include "ct_io.h"

#define TAM_LINHA 100

// ldcont - lista dinâmica de contatos.

typedef struct sContato
{
    char *nome;
    char *telefones[2];
    char *ringtone;

} Contato;

typedef struct sNode
{
    Contato info;
    struct sNode *next;

} NODE;

void ldcont_init (NODE **ptr_Lista)
{
    *ptr_Lista = NULL;
}

int ldcont_vazia (NODE *Lista)
{
    if (Lista == NULL)
        return 1;
    return 0;
}

NODE *ldcont_getnode ()
{
    return (NODE *) malloc(sizeof(NODE));
}

int ldcont_addoa (NODE **ptr_Lista, Contato contato)
{
    // addoa - adicionar em ordem alfabética.

    NODE *aux = *ptr_Lista;
    NODE *novo_node = ldcont_getnode();
    NODE *node_anterior = aux;

    if (novo_node == NULL)
    {
        printf("\n>> Erro na alocacao de memoria do novo node.");
        return 1;
    }

    novo_node -> info = contato;
    novo_node -> next = NULL;

    if (ldcont_vazia(aux))
        *ptr_Lista = novo_node;
    else
    {
        while (aux != NULL)
        {
            if (ct_scompao(novo_node -> info.nome, aux -> info.nome) == 1)
            {
                novo_node -> next = aux;

                if (aux == *ptr_Lista)
                    *ptr_Lista = novo_node;
                else
                    node_anterior -> next = novo_node;

                return 0;
            }

            node_anterior = aux;
            aux = aux -> next;
        }

        node_anterior -> next = novo_node;
    }

    return 0;
}



NODE *ldcont_pesquisar_contato (NODE *Lista, char *nome, char *telefone)
{
    NODE *aux = Lista;
    int node_encontrado = 0;

    while (aux != NULL && !node_encontrado)
    {
        if (ct_equals(aux -> info.nome, nome) &&
           (ct_equals(aux -> info.telefones[0], telefone) ||
            ct_equals(aux -> info.telefones[1], telefone)))
        {
            node_encontrado = 1;
        }
        else
            aux = aux -> next;
    }

    return aux;
}

void ldcont_excluir_contato (Contato contato)
{
    free(contato.nome);
    free(contato.telefones[0]);
    free(contato.telefones[1]);
    free(contato.ringtone);
}

int ldcont_remover (NODE **ptr_Lista, char *nome, char *telefone)
{
    NODE *alvo;
    NODE *aux, *node_anterior;
    int node_removido = 0;

    alvo = ldcont_pesquisar_contato (*ptr_Lista, nome, telefone);

    if (alvo == NULL)
        return 1;

    aux = *ptr_Lista;
    node_anterior = aux;

    while (aux != NULL && !node_removido)
    {
        if (aux == alvo)
        {
            ldcont_excluir_contato(aux -> info);

            if (aux == *ptr_Lista)
                *ptr_Lista = aux -> next;
            else
                node_anterior -> next = aux -> next;

            node_removido = 1;
        }
        else
        {
            node_anterior = aux;
            aux = aux -> next;
        }
    }

    return 0;
}

void ldcont_cadastrar_contato (NODE **ptr_Lista)
{
    Contato contato;

    printf("\n[CADASTRANDO CONTATO]\n");
    contato.nome = ct_getline(TAM_LINHA, ".. Insira o nome..: ");
    contato.telefones[0] = ct_getline(TAM_LINHA, ".. Insira o telefone 1..: ");
    contato.telefones[1] = ct_getline(TAM_LINHA, ".. Insira o telefone 2..: ");
    contato.ringtone = ct_getline(TAM_LINHA, ".. Insira o ringtone..: ");

    if (contato.nome == NULL ||
        contato.telefones[0] == NULL ||
        contato.telefones[1] == NULL ||
        contato.ringtone == NULL)
    {
        printf("\n>> Erro ao cadastrar o contato.");
    }
    else
    {
        if (ldcont_addoa(ptr_Lista, contato) == 0)
            printf("\n>> Contato cadastrado com sucesso!");
        else
            printf("\n>> Erro ao cadastrar o contato.");
    }
}

void ldcont_remover_contato (NODE **ptr_Lista)
{
    char nome[100];
    char telefone[100];

    if (ldcont_vazia(*ptr_Lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n[REMOVENDO CONTATO]\n");
        ct_scanline(nome, 100, "\n.. Insira o nome..: ");
        ct_scanline(telefone, 100, ".. Insira um dos telefones do contato..: ");

        if (ldcont_remover(ptr_Lista, nome, telefone) == 0)
            printf("\n>> Contato removido com sucesso!");
        else
            printf("\n>> Contato nao encontrado.");
    }
}

void ldcont_exibir_contato (Contato contato)
{
    printf("\n>> Contato:");
    printf("\n\t> Nome: %s", contato.nome);
    printf("\n\t> Telefone 1: %s", contato.telefones[0]);
    printf("\n\t> Telefone 2: %s", contato.telefones[1]);
    printf("\n\t> Ringtone: %s", contato.ringtone);
}

void ldcont_pesquisar_exibir_contato (NODE *Lista)
{
    NODE *aux;
    char nome[100], telefone[100];

    if (ldcont_vazia(Lista))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n[PESQUISANDO CONTATO]\n");
        ct_scanline(nome, 100, "\n.. Insira o nome..: ");
        ct_scanline(telefone, 100, ".. Insira um dos telefones do contato..: ");

        aux = ldcont_pesquisar_contato(Lista, nome, telefone);

        if (aux != NULL)
            ldcont_exibir_contato(aux -> info);
        else
            printf("\n>> Contato nao encontrado.");
    }
}

void ldcont_exibir_contatos (NODE *Lista)
{
    NODE *aux = Lista;

    if (ldcont_vazia(aux))
        printf("\n>> Lista vazia.");
    else
    {
        printf("\n[LISTA DE CONTATOS]\n");

        while (aux != NULL)
        {
            ldcont_exibir_contato(aux -> info);
            printf("\n");
            aux = aux -> next;
        }
    }
}
