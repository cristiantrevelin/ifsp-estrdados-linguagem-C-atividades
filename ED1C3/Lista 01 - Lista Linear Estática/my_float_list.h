#define TF 50

typedef struct lista_float
{
    float valores[TF];
    int n;

} LISTA_FLOAT;

void lista_float_inicializar (LISTA_FLOAT *Lista)
{
    Lista -> n = -1;
}

int lista_float_cheia (LISTA_FLOAT *Lista)
{
    if (Lista -> n + 1 == TF)
        return 1;
    else
        return 0;
}

int lista_float_vazia (LISTA_FLOAT *Lista)
{
    if (Lista -> n == -1)
        return 1;
    else
        return 0;
}

int lista_float_inserir_posicao (LISTA_FLOAT *Lista, int posicao, float elemento)
{
    int i;

    if (lista_float_cheia(Lista))
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
        Lista -> valores[i] = Lista -> valores[i - 1];

    Lista -> valores[posicao] = elemento;
    Lista -> n++;

    return 0;
}

int lista_float_inserir_ordem_crescente (LISTA_FLOAT *Lista, float elemento)
{
    int i, elemento_inserido = 0;

    if (lista_float_cheia(Lista))
    {
        printf("\n>> Erro - Lista cheia.");
        return 1;
    }

    if (elemento > Lista -> valores[Lista -> n])
        lista_float_inserir_posicao(Lista, Lista -> n+1, elemento);
    else
    {
    	i = 0;
    	while (i <= Lista -> n && !elemento_inserido)
    	{
            if (Lista -> valores[i] >= elemento)
            {
                lista_float_inserir_posicao(Lista, i, elemento);
                elemento_inserido = 1;
            }
        	
            i++;
    	}
    }

    return 0;
}

int lista_float_remover_posicao (LISTA_FLOAT *Lista, int posicao)
{
    int i;

    if (posicao < 0 || posicao > Lista -> n)
    {
        printf("\n>> Erro - Posicao invalida.");
        return 1;
    }

    for (i = posicao; i < Lista -> n; i++)
        Lista -> valores[i] = Lista -> valores[i + 1];

    Lista -> n--;

    return 0;
}

int lista_float_remover_elemento (LISTA_FLOAT *Lista, float elemento)
{
    int i, qnt_elementos_removidos = 0;

    for (i = 0; i <= Lista -> n; i++)
    {
        if (Lista -> valores[i] == elemento)
        {
            lista_float_remover_posicao(Lista, i);
            qnt_elementos_removidos++;
            i--;
        }
    }

    return qnt_elementos_removidos;
}

int lista_float_exibir_elementos (LISTA_FLOAT *Lista)
{
    int i;

    if (lista_float_vazia(Lista))
    {
        printf("\n>> Erro - Lista vazia.");
        return 1;
    }

    printf("\n>> Lista: ");

    for (i = 0; i <= Lista -> n; i++)
    {
        printf("%.2f", Lista -> valores[i]);

        if (i != Lista -> n)
            printf(", ");
    }

    return 0;
}
