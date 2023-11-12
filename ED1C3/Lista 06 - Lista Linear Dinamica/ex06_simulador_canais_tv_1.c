#include <stdio.h>
#include "ldc_ctv.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("----------- [SIMULADOR - CANAIS DE TV] -----------");
    printf("\n[1] Cadastrar Canal;");
    printf("\n[2] Remover Canal;");
    printf("\n[3] Iniciar Simulador;");

    printf("\n\n[0] Encerrar Menu.");
    printf("\n--------------------------------------------------");

    do
    {
        ct_uscanint(&opcao, "\n.. Insira a opcao..: ", "\t>> Opcao invalida.");

        if (opcao < 0 || opcao > 3)
            printf("\t>> Opcao invalida.");

    } while (opcao < 0 || opcao > 3);

    return opcao;
}

void executar_menu (CTV_NODE **ptr_lista)
{
    int executando = 1;
    char enter[2];

    do
    {
        switch (menu())
        {
        case 0:
            executando = 0;
            break;

        case 1:
            ldcctv_uaddfim(ptr_lista);
            break;

        case 2:
            ldcctv_uremover_canal(ptr_lista);
            break;

        case 3:
            ldcctv_simular_canais(*ptr_lista);
            break;

        default:
            break;
        }

        if (executando)
            ct_scanline(enter, 2, "\n\n[PRESSIONE ENTER PARA CONTINUAR]");

    } while (executando);

    printf("\n>> Menu encerrado.\n");
}

void main ()
{
    CTV_NODE *lista;
    ldcctv_init(&lista);

    executar_menu(&lista);
}
