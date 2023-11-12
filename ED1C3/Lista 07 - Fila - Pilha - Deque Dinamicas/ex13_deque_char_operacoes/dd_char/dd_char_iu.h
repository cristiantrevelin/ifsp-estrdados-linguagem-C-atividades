#include "dd_char.h"
#include "../../ct_headers/ct_io.h"

// ddciu: deque dinâmica de chars IU (Interface do Usuário).

int ddciu_menu ()
{
    int opcao;

    system("cls");

    printf("-------- [MENU - DEQUE DINAMICA DE CHARS] --------");
    printf("\n[1] Inserir elemento no inicio;");
    printf("\n[2] Inserir elemento no fim;");
    printf("\n[3] Remover elemento do inicio;");
    printf("\n[4] Remover elemento do fim;");
    printf("\n[5] Exibir elementos da deque;");

    printf("\n\n[0] Encerrar menu.");
    printf("\n--------------------------------------------------");

    do
    {
        ct_uscanint(&opcao, "\n.. Insira a opcao..: ", "\t> Valor invalido.");

        if (opcao < 0 || opcao > 5)
            printf("\t> Opcao invalida.");

    } while (opcao < 0 || opcao > 5);


    return opcao;
}

void ddciu_inserir_inicio (DDC *Deque)
{
    char elemento;

    printf("\n>> Inserindo Elemento Char no Inicio:");
    ct_uscanchar(&elemento, "\n.. Insira o elemento..: ", "\t> Insira um valor!");


    if (ddc_inserir_inicio(Deque, elemento) == 0)
        printf("\n>> Elemento inserido com sucesso.");
    else
        printf("\n>> Nao foi possivel inserir o elemento.");
}

void ddciu_inserir_fim (DDC *Deque)
{
    char elemento;

    printf("\n>> Inserindo Elemento Char no Fim:");
    ct_uscanchar(&elemento, "\n.. Insira o elemento..: ", "\t> Insira um valor!");


    if (ddc_inserir_fim(Deque, elemento) == 0)
        printf("\n>> Elemento inserido com sucesso.");
    else
        printf("\n>> Nao foi possivel inserir o elemento.");
}

void ddciu_remover_inicio (DDC *Deque)
{
    if (ddc_remover_inicio(Deque) == '\0')
        printf("\n>> Deque vazia!");
    else
        printf("\n>> Elemento removido com sucesso!");
}

void ddciu_remover_fim (DDC *Deque)
{
    if (ddc_remover_fim(Deque) == '\0')
        printf("\n>> Deque vazia!");
    else
        printf("\n>> Elemento removido com sucesso!");
}

void ddciu_exibir_elementos (DDC *Deque)
{
    DDC aux_Deque;
    char elemento;

    if (ddc_vazia(Deque))
        printf("\n>> Deque vazia!");
    else
    {
        ddc_init(&aux_Deque);
        printf("\n>> Exibindo Deque:");

        while (!ddc_vazia(Deque))
        {
            elemento = ddc_remover_inicio(Deque);
            printf("\n\t> Elemento: %c", elemento);
            ddc_inserir_inicio(&aux_Deque, elemento);
        }

        ddc_transferir(Deque, &aux_Deque);
    }
}

void ddciu_executar_menu (DDC *Deque)
{
    int menu_executando = 1;
    char enter;

    do
    {
        switch (ddciu_menu())
        {
        case 0:
            menu_executando = 0;
            break;

        case 1:
            ddciu_inserir_inicio(Deque);
            break;

        case 2:
            ddciu_inserir_fim(Deque);
            break;

        case 3:
            ddciu_remover_inicio(Deque);
            break;

        case 4:
            ddciu_remover_fim(Deque);
            break;

        case 5:
            ddciu_exibir_elementos(Deque);
            break;

        default:
            break;
        }

        if (menu_executando)
            ct_scanchar(&enter, "\n\n[PRESSIONE ENTER PARA CONTINUAR]");

    } while (menu_executando);

    printf("\n>> Menu Encerrado.\n");
}
