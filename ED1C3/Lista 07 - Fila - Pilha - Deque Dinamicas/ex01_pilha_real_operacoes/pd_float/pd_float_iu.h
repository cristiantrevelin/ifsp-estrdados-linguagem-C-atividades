#include "pd_float.h"
#include "../../ct_headers/ct_io.h"

// pdfiu: pilha dinâmica de floats IU (Interface do Usuário).

static int pdfiu_menu ()
{
    int opcao;

    system("cls");

    printf("--------- [MENU - PILHA DINAMICA - FLOAT] ---------");
    printf("\n[1] Empilhar elemento;");
    printf("\n[2] Desempilhar elemento;");
    printf("\n[3] Exibir elementos;");

    printf("\n\n[0] Encerrar menu.");
    printf("\n---------------------------------------------------");

    do
    {
        ct_uscanint(&opcao, "\n..Insira a opcao..: ", "\t> Erro - Valor invalido.");

        if (opcao < 0 || opcao > 3)
            printf("\t> Erro - Opcao invalida.");

    } while (opcao < 0 || opcao > 3);

    return opcao;
}

static void pdfiu_empilhar (PDF_NODE **ptr_pilha)
{
    float valor;

    printf("\n>> Empilhando Elemento Float:");
    ct_uscanfloat(&valor, "\n.. Insira o valor..: ", "\t> Erro - valor invalido.");

    if (pdf_push(ptr_pilha, valor) == 0)
        printf("\n>> Elemento empilhado com sucesso!");
    else
        printf("\n>> Erro ao alocar memoria para o node.");
}

static void pdfiu_desempilhar (PDF_NODE **ptr_pilha)
{
    if (pdf_vazia(*ptr_pilha))
        printf("\n>> Erro - pilha vazia.");
    else
        printf("\n>> Elemento desempilhado: %.3f", pdf_pop(ptr_pilha));
}

static void pdfiu_exibir_pilha (PDF_NODE **ptr_pilha)
{
    PDF_NODE *pilha_aux;
    float valor_desempilhado;

    if (pdf_vazia(*ptr_pilha))
        printf("\n>> A pilha esta vazia.");
    else
    {
        pdf_init(&pilha_aux);

        printf("\n>> Exibindo Pilha:");

        while (!pdf_vazia(*ptr_pilha))
        {
            valor_desempilhado = pdf_pop(ptr_pilha);
            printf("\n\t> Elemento: %.3f", valor_desempilhado);
            pdf_push(&pilha_aux, valor_desempilhado);
        }

        pdf_transferir(ptr_pilha, &pilha_aux);
    }
}

void pdfiu_executar_menu (PDF_NODE **ptr_pilha)
{
    int executando_menu = 1;
    char enter[2];

    do
    {
        switch (pdfiu_menu())
        {
        case 1:
            pdfiu_empilhar(ptr_pilha);
            break;

        case 2:
            pdfiu_desempilhar(ptr_pilha);
            break;

        case 3:
            pdfiu_exibir_pilha(ptr_pilha);
            break;

        case 0:
            executando_menu = 0;
            break;

        default:
            break;
        }

        if (executando_menu)
            ct_scanline(enter, 2, "\n\n[PRESSIONE ENTER PARA CONTINUAR]");

    } while (executando_menu);

    printf("\n>> Menu encerrado.\n");
}
