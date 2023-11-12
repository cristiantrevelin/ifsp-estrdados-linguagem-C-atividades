#include <stdio.h>
#include "LD_contatos.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("------------ [MENU - CONTATOS] ------------");
    printf("\n[1] Inserir novo contato;");
    printf("\n[2] Listar contatos;");
    printf("\n[3] Remover contato;");
    printf("\n[4] Pesquisar contato;");
    printf("\n\n[0] Encerrar menu.");
    printf("\n-------------------------------------------");

    do
    {
        ct_uscanint(&opcao, "\n.. Insira a opcao..: ", "\t>> Valor inserido invalido.");

        if (opcao > 4 || opcao < 0)
            printf("\t>> Opcao invalida.");

    } while (opcao > 4 || opcao < 0);

    return opcao;
}

void executar_menu (NODE **ptr_Lista)
{
    int menu_executando = 1;
    char enter[2];

    do
    {
        switch(menu())
        {
        case 1:
            ldcont_cadastrar_contato(ptr_Lista);
            break;

        case 2:
            ldcont_exibir_contatos(*ptr_Lista);
            break;

        case 3:
            ldcont_remover_contato(ptr_Lista);
            break;

        case 4:
            ldcont_pesquisar_exibir_contato(*ptr_Lista);
            break;

        case 0:
            menu_executando = 0;
            printf("\n>> Menu encerrado.");
            break;

        default:
            break;
        }

        if (menu_executando)
            ct_scanline(&enter, 2, "\n\n[PRESSIONE ENTER PARA CONTINUAR]");

    } while (menu_executando);

    printf("\n");
}

void main ()
{
    NODE *Lista;
    ldcont_init(&Lista);

    executar_menu(&Lista);
}
