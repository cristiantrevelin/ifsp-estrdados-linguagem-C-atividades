#include <stdio.h>
#include "my_int_list.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("[MENU - LISTA LINEAR ESTATICA - INT]");
    printf("\n[1] Inserir elemento na posicao desejada;");
    printf("\n[2] Remover elemento da posicao desejada;");
    printf("\n[3] Acessar elemento da posicao desejada;");
    printf("\n[4] Procurar elemento;");
    printf("\n[5] Exibir os elementos da lista;");
    printf("\n[-1] Encerrar o Programa.");

    printf("\n\n.. Insira o numero da opcao desejada..: ");
    scanf("%d", &opcao);

    return opcao;
}

void main ()
{
    int programa_aberto = 1;    ///boolean
    int posicao, elemento, *ptr_elemento;
    char enter;

    LISTA_INT Lista;

    lista_int_inicializar(&Lista);

    do
    {
        switch (menu())
        {

        case 1:
            printf("\n> Tamanho atual da lista: %d", lista_int_obter_tamanho(&Lista));
            printf("\n.. Insira a posicao..: ");
            scanf("%d", &posicao);

            printf(".. Insira o elemento..: ");
            scanf("%d", &elemento);

            if (!lista_int_inserir_posicao(&Lista, posicao, elemento))
                printf("\n>> Elemento inserido com sucesso.");

            break;

        case 2:
            printf("\n.. Insira a posicao..: ");
            scanf("%d", &posicao);

            if (!lista_int_remover_posicao(&Lista, posicao))
                printf("\n>> Elemento removido com sucesso.");

            break;

        case 3:
            printf("\n.. Insira a posicao..: ");
            scanf("%d", &posicao);

            ptr_elemento = lista_int_acessar_posicao(&Lista, posicao);

            if (ptr_elemento != NULL)
                printf("\n>> Elemento [%d] = %d", posicao, *ptr_elemento);

            break;

        case 4:
            printf("\n.. Insira o elemento..: ");
            scanf("%d", &elemento);

            posicao = lista_int_buscar_elemento(&Lista, elemento);

            if (posicao != -1)
                printf("\n>> Posicao do elemento [%d] = %d", elemento, posicao);
            else
                printf("\n>> Elemento nao encontrado.");

            break;

        case 5:
            lista_int_exibir_elementos(&Lista);

            break;

        case -1:
            programa_aberto = 0;

            break;

        default:
            printf("   >> Opcao invalida, tente novamente.");

            break;
        }

        if (programa_aberto)
        {
            fflush(stdin);
            printf("\n\n[PRESSIONE ENTER PARA CONTINUAR]");
            scanf("%c", &enter);
        }

    } while (programa_aberto);
}
