#include <stdio.h>
#define TAM_MAX 6

typedef struct sInt_Deque
{
    int valores[TAM_MAX];
    int inicio, fim;

} INT_DEQUE;

void deque_int_inicializar (INT_DEQUE *Deque)
{
    Deque -> inicio = TAM_MAX - 1;
    Deque -> fim = TAM_MAX - 1;
}

int deque_int_cheia (INT_DEQUE *Deque)
{
    int fim = Deque -> fim;

    fim = (fim + 1) % TAM_MAX;

    if (fim == Deque -> inicio)
        return 1;
    return 0;
}

int deque_int_vazia (INT_DEQUE *Deque)
{
    if (Deque -> inicio == Deque -> fim)
        return 1;
    return 0;
}

int deque_int_inserir_inicio (INT_DEQUE *Deque, int elemento)
{
    if (deque_int_cheia(Deque))
    {
        printf(">> Erro - Deque cheia.");
        return 1;
    }

    if (Deque -> inicio == 0)
        Deque -> inicio = TAM_MAX - 1;
    else
        Deque -> inicio--;

    Deque -> valores[(Deque -> inicio + 1) % TAM_MAX] = elemento;

    return 0;
}

int deque_int_inserir_fim (INT_DEQUE *Deque, int elemento)
{
    if (deque_int_cheia(Deque))
    {
        printf(">> Erro - Deque cheia.");
        return 1;
    }

    Deque -> fim = (Deque -> fim + 1) % TAM_MAX;
    Deque -> valores[Deque -> fim] = elemento;

    return 0;
}

int *deque_int_remover_inicio (INT_DEQUE *Deque)
{
    // Remove o elemento do início do Deque e retorna um ponteiro
    // para o elemento removido. Caso o Deque esteja vazio, retorna
    // NULL.

    int *auxiliar = NULL;

    if (deque_int_vazia(Deque))
        printf(">> Erro - Deque vazia.");
    else
    {
        Deque -> inicio = (Deque -> inicio + 1) % TAM_MAX;
        auxiliar = Deque -> valores + Deque -> inicio;
    }

    return auxiliar;
}

int *deque_int_remover_fim (INT_DEQUE *Deque)
{
    // Remove o elemento do fim do Deque e retorna um ponteiro
    // para o elemento removido. Caso o Deque esteja vazio, retorna
    // NULL.

    int *auxiliar = NULL;

    if (deque_int_vazia(Deque))
        printf(">> Erro - Deque vazia.");
    else
    {
        auxiliar = Deque -> valores + Deque -> fim;

        if (Deque -> fim == 0)
            Deque -> fim = TAM_MAX - 1;
        else
            Deque -> fim--;
    }

    return auxiliar;
}

void deque_int_imprimir_nc (INT_DEQUE *Deque)
{
    // nc = Impressao Nao Classica.

    int i = (Deque -> inicio + 1) % TAM_MAX;

    if (!deque_int_vazia(Deque))
    {
        printf("\n>> Deque: ");

        while (i != (Deque -> fim + 1) % TAM_MAX)
        {
            printf("%d", Deque -> valores[i]);

            if (i != Deque -> fim)
                printf(", ");

            i = (i + 1) % TAM_MAX;
        }
    }
    else
        printf(">> Erro - Deque vazia.");
}

int deque_int_imprimir (INT_DEQUE Deque)
{
    // Esvazia a Deque, exibindo os elementos a partir do inicio.

    int *elemento_removido;

    if (deque_int_vazia(&Deque))
    {
        printf(">> Erro - Deque vazia.");
        return 1;
    }

    printf("\n>> Deque: ");

    while (!deque_int_vazia(&Deque))
    {
        elemento_removido = deque_int_remover_inicio(&Deque);
        printf("%d", *elemento_removido);

        if (Deque.inicio != Deque.fim)
            printf(", ");
    }

    return 0;
}
