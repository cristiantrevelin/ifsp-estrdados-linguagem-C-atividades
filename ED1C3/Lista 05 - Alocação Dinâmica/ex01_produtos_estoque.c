#include <stdio.h>
#include <stdlib.h>
#define TAM_NOME 5

typedef struct sProduto
{
    int codigo;
    char nome[TAM_NOME];
    int quantidade;
    float preco_venda;

} Produto;

void inicializar_produto (Produto *produto)
{
    produto -> codigo = -1;
}

void inicializar_estoque (Produto *estoque, int qnt_estoque)
{
    int i;

    for (i = 0; i < qnt_estoque; i++)
        inicializar_produto(estoque + i);
}

int ler_quantidade (char *texto)
{
    int quantidade;

    do
    {
        printf("%s", texto);
        scanf("%d", &quantidade);

        if (quantidade <= 0)
            printf("   >> Quantidade invalida, tente novamente.\n");

    } while (quantidade <= 0);

    return quantidade;
}

int codigo_produto_existe (Produto *estoque, int qnt_estoque, int codigo_produto)
{
    int i;

    for (i = 0; i < qnt_estoque; i++)
    {

        if (codigo_produto == estoque[i].codigo)
            return 1;
    }

    return 0;
}

int ler_codigo_produto (Produto *estoque, int qnt_estoque)
{
    int codigo_produto, codigo_existe;

    do
    {
        printf("\n.. Insira o codigo do produto..: ");
        scanf("%d", &codigo_produto);

        codigo_existe = codigo_produto_existe(estoque, qnt_estoque, codigo_produto);

        if (codigo_produto < 0)
            printf("   >> Erro - O codigo inserido eh invalido.");

        else if (codigo_existe)
            printf("   >> Erro - O codigo inserido ja pertence a um produto.");

    } while (codigo_existe || codigo_produto < 0);

    return codigo_produto;
}

void ler_nome_produto (char *nome, int tam_nome)
{
    char caractere;
    int i = 0;

    printf(".. Insira o nome do produto..: ");
    fflush(stdin);

    do
    {
        caractere = getc(stdin);

        if (caractere != '\n')
        {
            nome[i] = caractere;
            i++;
        }

    } while (caractere != '\n' && i < tam_nome - 1);

    nome[i] = '\0';
    fflush(stdin);
}

float ler_preco_venda_produto ()
{
    float preco_venda;

    do
    {
        printf(".. Insira o preco de venda..: ");
        scanf("%f", &preco_venda);

        if (preco_venda <= 0)
            printf("   >> Preco de venda invalido, tente novamente.\n");

    } while (preco_venda <= 0);

    return preco_venda;
}

void cadastrar_produto (Produto *estoque, int qnt_estoque, Produto *produto)
{
    int codigo_produto, quantidade;
    char nome[TAM_NOME];
    float preco_venda;

    printf("\n[CADASTRANDO PRODUTO]:");

    produto -> codigo = ler_codigo_produto(estoque, qnt_estoque);
    ler_nome_produto(produto -> nome, TAM_NOME);
    produto -> quantidade = ler_quantidade(".. Insira a quantidade do produto..: ");
    produto -> preco_venda = ler_preco_venda_produto();
}

int cadastrar_estoque (Produto *estoque, int qnt_estoque)
{
    int i;

    if (qnt_estoque == 0)
    {
        printf(">> Erro - Estoque vazio.");
        return 1;
    }

    printf("\n<< CADASTRANDO O ESTOQUE >>\n");

    for (i = 0; i < qnt_estoque; i++)
        cadastrar_produto(estoque, qnt_estoque, &estoque[i]);

    return 0;
}

void apresentar_produto (Produto produto)
{
    printf("\n   >> Codigo: %d", produto.codigo);
    printf("\n   >> Nome: %s", produto.nome);
    printf("\n   >> Quantidade: %d", produto.quantidade);
    printf("\n   >> Preco de venda: %.2f", produto.preco_venda);
}

int apresentar_estoque (Produto *estoque, int qnt_estoque)
{
    int i;

    if (qnt_estoque == 0)
    {
        printf(">> Erro - Estoque vazio.");
        return 1;
    }

    printf("\n[APRESENTANDO O ESTOQUE]:");

    for (i = 0; i < qnt_estoque; i++)
    {
        printf("\n>> Produto %d:", i+1);
        apresentar_produto(estoque[i]);
        printf("\n");
    }

    return 0;
}

void main ()
{
    int qnt_estoque;
    Produto *estoque;

    qnt_estoque = ler_quantidade(".. Insira o tamanho do estoque..: ");
    estoque = (Produto *) malloc(qnt_estoque * sizeof(Produto));

    inicializar_estoque(estoque, qnt_estoque);

    cadastrar_estoque(estoque, qnt_estoque);
    apresentar_estoque(estoque, qnt_estoque);
}
