#include <stdio.h>
#define TAM_MAX 80

typedef struct char_stack
{
    char valores [TAM_MAX];
    int topo;

} CHAR_STACK;

void pilha_char_inicializar (CHAR_STACK *Pilha)
{
    Pilha -> topo = -1;
}

int pilha_char_cheia (CHAR_STACK *Pilha)
{
    if (Pilha -> topo == TAM_MAX - 1)
        return 1;
    return 0;
}

int pilha_char_vazia (CHAR_STACK *Pilha)
{
    if (Pilha -> topo == -1)
        return 1;
    return 0;
}

int pilha_char_push (CHAR_STACK *Pilha, char elemento)
{
    if (pilha_char_cheia(Pilha))
    {
        printf("\n>> Erro - Pilha cheia.");
        return 1;
    }

    Pilha -> topo++;
    Pilha -> valores[Pilha -> topo] = elemento;

    return 0;
}

// Insere uma palavra na Pilha (caractere por caractere) e retorna
// quantos caracteres da palavra foram inseridos.

int pilha_char_push_palavra (CHAR_STACK *Pilha)
{
    int cont_caracteres = 0;
    char caractere;

    pilha_char_inicializar(Pilha);

    fflush(stdin);
    printf("\n.. Insira o texto..: ");

    do
    {
        caractere = getc(stdin);

        if (caractere != '\n' && caractere != ' ' && !pilha_char_cheia(Pilha))
        {
            pilha_char_push(Pilha, caractere);
            cont_caracteres++;
        }

    } while (caractere != '\n' && caractere != ' ' && !pilha_char_cheia(Pilha));

    return cont_caracteres;
}

int pilha_char_apresentar (CHAR_STACK *Pilha)
{
    int i;

    if (pilha_char_vazia(Pilha))
    {
        printf("\n>> Erro - Pilha vazia.");
        return 1;
    }

    printf("\n>> Apresentando Pilha:");

    for (i = Pilha -> topo; i >= 0; i--)
        printf("\n   > Elemento [%d]: %c", i, Pilha -> valores[i]);

    return 0;
}

int pilha_char_verificar_palindromo (CHAR_STACK *Pilha)
{
    int i;
    int palindromo = 1;

    if (pilha_char_vazia(Pilha))
    {
        printf("\n>> Erro - Pilha vazia.");
        return -1;
    }

    for (i = 0; i <= Pilha -> topo / 2; i++)
    {
        if (Pilha -> valores[i] != Pilha -> valores[Pilha -> topo - i])
            palindromo = 0;
    }

    return palindromo;
}
