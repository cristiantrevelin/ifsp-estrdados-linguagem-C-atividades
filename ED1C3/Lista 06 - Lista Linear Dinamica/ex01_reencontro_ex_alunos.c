#include <stdio.h>
#include "LD_formandos.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("------------- [MENU - LISTA DE FORMANDOS] -------------");
    printf("\n[1] Cadastrar formando;");
    printf("\n[2] Remover formando pelo prontuario;");
    printf("\n[3] Exibir lista de formandos;");
    printf("\n[4] Listar formandos separados por curso;");
    printf("\n[5] Listar formandos separados por ano de formatura;");

    printf("\n\n[0] Encerrar programa.");
    printf("\n-------------------------------------------------------\n");

    do
    {
        ct_uscanint(&opcao, ".. Insira a opcao..: ", "\t>> Opcao invalida, tente novamente.");

        if (opcao < 0 || opcao > 5)
            printf("\t>> Opcao invalida, tente novamente.\n");

    } while (opcao < 0 || opcao > 5);

    return opcao;
}

void executar_menu_lista (CELULA **ptr_Lista)
{
    int prontuario, ano;
    char *curso;

    int programa_executando = 1;
    char enter;

    do
    {
        switch (menu())
        {
        case 0:
            programa_executando = 0;
            printf("\n>> Programa encerrado.");
            break;

        case 1:
            *ptr_Lista = cadastrar_formando(*ptr_Lista);
            printf("\n>> Formando cadastrado com sucesso!");
            break;

        case 2:
            prontuario = ler_prontuario(*ptr_Lista, 'p');
            *ptr_Lista = lista_remover_prontuario(*ptr_Lista, prontuario);
            break;

        case 3:
            lista_exibir(*ptr_Lista);
            break;

        case 4:
            lista_exibir_todos_curso(*ptr_Lista);
            break;

        case 5:
            lista_exibir_todos_ano_formatura(*ptr_Lista);
            break;

        default:
            break;
        }

        if (programa_executando)
        {
            fflush(stdin);
            printf("\n\n[PRESSIONE ENTER PARA CONTINUAR]");
            scanf("%c", &enter);
        }

    } while (programa_executando);

    printf("\n");
}

void main ()
{
    CELULA *Lista;
    lista_init(&Lista);

    executar_menu_lista(&Lista);
}
