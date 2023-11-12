#define TF 50

typedef struct lista_int
{
    int valores[TF];
    int n;

} LISTA_INT;

void lista_int_inicializar (LISTA_INT *Lista)
{
    Lista -> n = -1;
}

int lista_int_cheia (LISTA_INT *Lista)
{
    if (Lista -> n + 1 == TF)
        return 1;
    else
        return 0;
}

int lista_int_vazia (LISTA_INT *Lista)
{
    if (Lista -> n == -1)
        return 1;
    else
        return 0;
}

int lista_int_inserir_posicao (LISTA_INT *Lista, int posicao, int elemento)
{
    int i;

    if (lista_int_cheia(Lista))
    {
        printf("\n>> Erro - Lista cheia.");
        return 1;
    }

    if (posicao < 0 || posicao > Lista -> n + 1)
    {
        printf("\n>> Erro - Posicao invalida.");
        return 1;
    }

    for (i = Lista -> n + 1; i > posicao; i--)
        Lista -> valores[i] = Lista -> valores[i-1];

    Lista -> valores[posicao] = elemento;
    Lista -> n++;

    return 0;
}

int lista_int_remover_posicao (LISTA_INT *Lista, int posicao)
{
    int i;

    if (posicao < 0 || posicao > Lista -> n)
    {
        printf("\n>> Erro - Posicao invalida.");
        return 1;
    }

    for (i = posicao; i < Lista -> n; i++)
        Lista -> valores[i] = Lista -> valores[i+1];

    Lista -> n--;

    return 0;
}

int lista_int_exibir_elementos (LISTA_INT *Lista)
{
    int i;

    if (lista_int_vazia(Lista))
    {
        printf("\n>> Erro - Lista vazia.");
        return 1;
    }

    printf("\n>> Lista: ");

    for (i = 0; i < Lista -> n+1; i++)
    {
        printf("%d", Lista -> valores[i]);

        if (i != Lista -> n)
            printf(", ");
    }


    return 0;
}

int lista_int_obter_tamanho (LISTA_INT *Lista)
{
    return Lista -> n + 1;
}

int *lista_int_acessar_posicao (LISTA_INT *Lista, int posicao)
{
    int *ptr_elemento = NULL;

    if (posicao < 0 || posicao > Lista -> n)
        printf("\n>> Erro - Posicao invalida.");
    else
        ptr_elemento = (Lista -> valores) + posicao;

    return ptr_elemento;
}

int lista_int_buscar_elemento (LISTA_INT *Lista, int elemento)
{
    int posicao = -1, i;
    int elemento_encontrado = 0;    ///boolean

    i = 0;

    while (i <= Lista -> n && !elemento_encontrado)
    {
        if (Lista -> valores[i] == elemento)
        {
            posicao = i;
            elemento_encontrado = 1;
        }

        i++;
    }

    return posicao;
}

int lista_int_concatenar_listas (LISTA_INT *Lista_1, LISTA_INT *Lista_2)
{
    int i, lista1_tl, lista2_tl;

    lista1_tl = lista_int_obter_tamanho(Lista_1);
    lista2_tl = lista_int_obter_tamanho(Lista_2);

    if (lista1_tl + lista2_tl > TF)
    {
        printf("\n>> Erro - A quantidade de elementos ultrapassa a capacidade da lista.");
        return 1;
    }

    for (i = 0; i <= Lista_2 -> n; i++)
        Lista_1 -> valores[lista1_tl + i] = Lista_2 -> valores[i];

    Lista_1 -> n += lista2_tl;

    return 0;
}
