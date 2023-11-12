#include <stdio.h>
#include <stdlib.h>
#include "my_int_queue.h"

int menu ()
{
    int opcao;

    system("cls");

    printf("[MENU - FILA ESTATICA CIRCULAR - INT]: ---------------------------");
    printf("\n[1] Enfileirar elemento;");
    printf("\n[2] Desenfileirar elemento;");

    printf("\n\n[3] Apresentar filas;");
    printf("\n[4] Comparar filas;");
    printf("\n[5] Reiniciar filas;");

    printf("\n\n[-1] Encerrar o programa.");
    printf("\n------------------------------------------------------------------");
    printf("\n.. Insira a opcao desejada..: ");
    scanf("%d", &opcao);

    return opcao;
}

int selecionar_fila ()
{
    int escolha = -1;

    printf("\n.. Insira a FILA a ser manipulada (1 ou 2)..: ");

    do
    {
        scanf("%d", &escolha);

        if (escolha != 1 && escolha != 2)
            printf(">> FILA invalida, insira 1 ou 2..: ");

    } while (escolha != 1 && escolha != 2);

    return escolha;
}

void main ()
{
    int programa_aberto = 1;
    int elemento, fila_manipulada, controle_saida;
    int *elemento_desenfileirado;

    char enter;

    INT_QUEUE *Fila_1 = (INT_QUEUE *) malloc(sizeof(INT_QUEUE));
    INT_QUEUE *Fila_2 = (INT_QUEUE *) malloc(sizeof(INT_QUEUE));

    fila_int_inicializar(Fila_1);
    fila_int_inicializar(Fila_2);

    do
    {
        switch (menu())
        {
        case 1:
            fila_manipulada = selecionar_fila();

            printf("\n.. Insira o elemento..: ");
            scanf("%d", &elemento);

            if (fila_manipulada == 1)
                controle_saida = fila_int_enfileirar(Fila_1, elemento);
            else
                controle_saida = fila_int_enfileirar(Fila_2, elemento);

            if (controle_saida == 0)
                printf(">> Elemento enfileirado com sucesso!");

            break;

        case 2:
            fila_manipulada = selecionar_fila();

            if (fila_manipulada == 1)
                elemento_desenfileirado = fila_int_desenfileirar(Fila_1);
            else
                elemento_desenfileirado = fila_int_desenfileirar(Fila_2);

            if (elemento_desenfileirado != NULL)
                printf("\n>> Elemento desenfileirado com sucesso!");

            break;

        case 3:
            printf("\n>> Fila 1:");
            fila_int_apresentar(*Fila_1);

            printf("\n\n>> Fila 2:");
            fila_int_apresentar(*Fila_2);

            break;

        case 4:
            if (fila_int_maior_que(*Fila_1, *Fila_2))
                printf("\n>> Fila 1 possui mais elementos que a Fila 2!");
            else
                printf("\n>> Fila 1 possui menos, ou a mesma quantidade de elementos, que a Fila 2.");

            break;

        case 5:
            fila_int_inicializar(Fila_1);
            fila_int_inicializar(Fila_2);

            printf("\n>> Filas reiniciadas!");

            break;

        case -1:
            programa_aberto = 0;
            printf("\n>> Programa encerrado.");

            break;

        default:
            printf("\n>> Opcao invalida, tente novamente.");
            break;
        }

        if (programa_aberto)
        {
            fflush(stdin);
            printf("\n\n[PRESSIONE ENTER PARA CONTINUAR]");
            scanf("%c", &enter);
        }

    } while (programa_aberto);

    printf("\n");
}
