#include "fd_int.h"
#include "../../ct_headers/ct_io.h"

// fdiiu: fila dinâmica de ints IU (Interface do Usuário).

static int fdiiu_menu ()
{
    int opcao;

    system("cls");

    printf("--------- [MENU - CONSULTORIO - ATENDIMENTO] ---------");
    printf("\n[1] Gerar senha;");
    printf("\n[2] Chamar proxima senha;");

    printf("\n\n[0] Encerrar menu.");
    printf("\n------------------------------------------------------");

    do
    {
        ct_uscanint(&opcao, "\n..Insira a opcao..: ", "\t> Erro - Valor invalido.");

        if (opcao < 0 || opcao > 2)
            printf("\t> Erro - Opcao invalida.");

    } while (opcao < 0 || opcao > 2);

    return opcao;
}

void fdiiu_gerar_senha (FDI *fila)
{
    int senha;

    printf("\n>> Gerando nova senha:");
    senha = fdi_getfim(fila) + 1;

    printf("\n\t> Senha gerada: %d", senha);
    fdi_enfileirar(fila, senha);
    printf("\n\t> Senha movida ao fim da fila!");
}

void fdiiu_chamar_senha (FDI *fila)
{
    int senha;

    if (fdi_vazia(fila))
        printf("\n>> Nao ha senhas na fila.");
    else
    {
        printf("\n>> Chamando proxima senha!");
        senha = fdi_desenfileirar(fila);
        printf("\n>> SENHA: %d - Dirija-se ao consultorio.", senha);
    }
}

void fdiiu_executar_menu (FDI *fila)
{
    int menu_executando = 1;
    char enter[2];

    do
    {
        switch (fdiiu_menu())
        {
        case 0:
            menu_executando = 0;
            break;

        case 1:
            fdiiu_gerar_senha(fila);
            break;

        case 2:
            fdiiu_chamar_senha(fila);
            break;

        default:
            break;
        }

        if (menu_executando)
            ct_scanline(enter, 2, "\n\n[PRESSIONE ENTER PARA CONTINUAR]");

    } while (menu_executando);

    printf("\n>> Menu encerrado.\n");
}
