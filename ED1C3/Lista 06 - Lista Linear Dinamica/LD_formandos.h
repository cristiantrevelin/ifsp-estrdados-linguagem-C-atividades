#include <stdio.h>
#include <stdlib.h>
#include "ct_io.h"
#include "ct_string.h"

typedef struct sFormando
{
    char *nome_completo, *nome_curso;
    int prontuario, ano_ingresso, ano_formatura;
    char *endereco;
    char *telefones[2];

} Formando;

typedef struct celula
{
    Formando info;
    struct celula *next;

} CELULA;

void lista_init (CELULA **Lista)
{
    *Lista = NULL;
}

int lista_vazia (CELULA *Lista)
{
    if (Lista == NULL)
        return 1;
    return 0;
}

CELULA *get_node ()
{
    return (CELULA *) malloc(sizeof(CELULA));
}

CELULA *lista_inserir_fim (CELULA *Lista, Formando formando)
{
    CELULA *auxiliar, *novo_no;

    novo_no = get_node();

    if (novo_no == NULL)
        printf(">> Erro na alocacao de memoria do novo no.");
    else
    {
        novo_no -> info = formando;
        novo_no -> next = NULL;

        if (lista_vazia(Lista))
            Lista = novo_no;
        else
        {
            auxiliar = Lista;

            while (auxiliar -> next != NULL)
                auxiliar = auxiliar -> next;

            auxiliar -> next = novo_no;
        }
    }

    return Lista;
}

int lista_get_tamanho (CELULA *Lista)
{
    int tamanho = 0;
    CELULA *auxiliar = Lista;

    while (auxiliar != NULL)
    {
        tamanho++;
        auxiliar = auxiliar -> next;
    }

    return tamanho;
}

void apagar_formando (Formando formando)
{
    free(formando.endereco);
    free(formando.nome_completo);
    free(formando.nome_curso);
    free(formando.telefones[0]);
    free(formando.telefones[1]);
}

CELULA *lista_remover_prontuario (CELULA *Lista, int prontuario)
{
    CELULA *auxiliar, *no_anterior;
    int qnt_removidos = 0;

    auxiliar = Lista;

    if (lista_vazia(auxiliar))
        printf("\n>> Erro - Lista vazia.");
    else
    {
        while (auxiliar != NULL)
        {
            if (auxiliar -> info.prontuario == prontuario)
            {
                if (auxiliar == Lista)
                    Lista = auxiliar -> next;
                else
                    no_anterior -> next = auxiliar -> next;

                apagar_formando(auxiliar -> info);
                free(auxiliar);
                qnt_removidos++;
            }

            no_anterior = auxiliar;
            auxiliar = auxiliar -> next;
        }

        if (qnt_removidos == 0)
            printf("\n>> Prontuario nao encontrado.");
        else
            printf("\n>> %d elemento(s) removido(s) com sucesso!", qnt_removidos);
    }

    return Lista;
}

void exibir_formando (Formando formando)
{
    printf("\n>> Formando: ");
    printf("\n\t> Nome: %s", formando.nome_completo);
    printf("\n\t> Curso: %s", formando.nome_curso);
    printf("\n\t> Prontuario: %d", formando.prontuario);
    printf("\n\t> Ano de Ingresso: %d", formando.ano_ingresso);
    printf("\n\t> Ano de Formatura: %d", formando.ano_formatura);
    printf("\n\t> Endereco: %s", formando.endereco);
    printf("\n\t> Telefone 1: %s", formando.telefones[0]);
    printf("\n\t> Telefone 2: %s", formando.telefones[1]);
}

void lista_exibir (CELULA *Lista)
{
    CELULA *auxiliar = Lista;

    if (auxiliar == NULL)
        printf("\n>> A lista esta vazia.");
    else
    {
        printf("\n[EXIBINDO A LISTA DE FORMANDOS]:\n");

        while (auxiliar != NULL)
        {
            exibir_formando(auxiliar -> info);
            auxiliar = auxiliar -> next;
            printf("\n");
        }
    }
}

void lista_exibir_curso (CELULA *Lista, char *curso)
{
    CELULA *auxiliar = Lista;
    int qnt_exibidos = 0;

    if (lista_vazia(auxiliar))
        printf("\n>> A lista esta vazia.");
    else
    {
        printf("\n>> Curso: %s\n", curso);

        while (auxiliar != NULL)
        {
            if (ct_equals(curso, auxiliar -> info.nome_curso))
            {
                exibir_formando(auxiliar -> info);
                qnt_exibidos++;

                printf("\n");
            }

            auxiliar = auxiliar -> next;
        }

        if (qnt_exibidos == 0)
            printf(">> Nao ha formandos do curso %s", curso);
    }
}

void lista_exibir_todos_curso (CELULA *Lista)
{
    char *cursos[lista_get_tamanho(Lista)];
    int cursos_tl = 0, i;
    int curso_apresentado = 0;

    CELULA *auxiliar = Lista;

    if (lista_vazia(auxiliar))
        printf("\n>> A lista esta vazia.");
    else
    {
        printf("\n[EXIBINDO FORMANDOS POR CURSO]\n");

        while (auxiliar != NULL)
        {
            i = 0;

            while (i < cursos_tl && !curso_apresentado)
            {
                if (ct_equals(auxiliar -> info.nome_curso, cursos[i]))
                    curso_apresentado = 1;

                i++;
            }

            if (!curso_apresentado)
            {
                lista_exibir_curso(Lista, auxiliar -> info.nome_curso);

                cursos[cursos_tl] = ct_get_scopy(auxiliar -> info.nome_curso);
                cursos_tl++;
            }

            curso_apresentado = 0;
            auxiliar = auxiliar -> next;
        }
    }
}

void lista_exibir_ano_formatura (CELULA *Lista, int ano_formatura)
{
    CELULA *auxiliar = Lista;
    int qnt_exibidos = 0;

    if (lista_vazia(auxiliar))
        printf("\n>> A lista esta vazia.");
    else
    {
        printf("\n>> Ano de Formatura: %d\n", ano_formatura);

        while (auxiliar != NULL)
        {
            if (auxiliar -> info.ano_formatura == ano_formatura)
            {
                exibir_formando(auxiliar -> info);
                qnt_exibidos++;

                printf("\n");
            }

            auxiliar = auxiliar -> next;
        }

        if (qnt_exibidos == 0)
            printf(">> Nao ha formandos do ano %d", ano_formatura);
    }
}

int *lista_get_anos_formatura (CELULA *Lista, int ordenar)
{
    CELULA *auxiliar = Lista;
    int *anos = NULL, anos_tl = 0, tam_lista;

    int i, j, menor_ano = 0;

    if (!lista_vazia(auxiliar))
    {
        tam_lista = lista_get_tamanho(Lista);
        anos = (int *) malloc(tam_lista * sizeof(int));

        while (auxiliar != NULL)
        {
            anos[anos_tl] = auxiliar -> info.ano_formatura;
            anos_tl ++;

            auxiliar = auxiliar -> next;
        }

        if (ordenar)
        {
            int anos_aux[anos_tl];

            for (i = 0; i < anos_tl; i++)
            {
                for (j = 0; j < anos_tl; i++)
                {
                    if (j == 0 || anos[j] < menor_ano)
                        menor_ano = anos[j];
                }
            }
        }

        anos[anos_tl] = -1;   // fim do array.
        anos_tl++
    }

    return anos;
}

void lista_exibir_todos_ano_formatura (CELULA *Lista)
{
    int anos[lista_get_tamanho(Lista)];
    int anos_tl = 0, i;
    int ano_apresentado = 0;

    CELULA *auxiliar = Lista;

    if (lista_vazia(auxiliar))
        printf("\n>> A lista esta vazia.");
    else
    {
        printf("\n[EXIBINDO FORMANDOS POR ANO DE FORMATURA]\n");

        while (auxiliar != NULL)
        {
            i = 0;

            while (i < anos_tl && !ano_apresentado)
            {
                if (auxiliar -> info.ano_formatura == anos[i])
                    ano_apresentado = 1;

                i++;
            }

            if (!ano_apresentado)
            {
                lista_exibir_ano_formatura(Lista, auxiliar -> info.ano_formatura);
                anos[anos_tl] = auxiliar -> info.ano_formatura;
                anos_tl++;
            }

            ano_apresentado = 0;
            auxiliar = auxiliar -> next;
        }
    }
}

int prontuario_existe (CELULA *Lista, int prontuario)
{
    if (lista_vazia(Lista))
        return 0;

    CELULA *auxiliar = Lista;

    while (auxiliar != NULL)
    {
        if (auxiliar -> info.prontuario == prontuario)
            return 1;

        auxiliar = auxiliar -> next;
    }

    return 0;
}

int prontuario_invalido (int prontuario)
{
    if (prontuario < 0)
        return 1;
    return 0;
}

int ler_prontuario (CELULA *Lista, char modo)
{
    int prontuario = -1;

    if (modo == 'i')
    {
        do
        {
            ct_uscanint(&prontuario, ".. Insira o prontuario..: ", "\t>> Erro - Prontuario invalido.");

            if (prontuario_invalido(prontuario))
                printf("\t>> Erro - Prontuario invalido.\n");

            else if (prontuario_existe(Lista, prontuario))
                printf("\t>> Erro - O prontuario inserido ja existe.\n");

        } while (prontuario_existe(Lista, prontuario) || prontuario_invalido(prontuario));
    }

    else if (modo == 'p')
    {
        do
        {
            ct_uscanint(&prontuario, ".. Insira o prontuario..: ", "\t>> Erro - Prontuario invalido.");

            if (prontuario_invalido(prontuario))
                printf("\t>> Erro - Prontuario invalido.\n");

        } while (prontuario_invalido(prontuario));
    }

    else
        printf("\n>> Erro - Modo invalido.");

    return prontuario;
}

CELULA *cadastrar_formando (CELULA *Lista)
{
    Formando formando;

    printf("\n[CADASTRANDO FORMANDO]:\n");

    formando.nome_completo = ct_getline(100, ".. Insira o nome completo..: ");
    formando.nome_curso = ct_getline(100, ".. Insira o nome do curso..: ");
    formando.prontuario = ler_prontuario(Lista, 'i');

    ct_uscanint(&(formando.ano_ingresso), ".. Insira o ano de ingresso..: ", "\t>> Valor inserido invalido.");
    ct_uscanint(&(formando.ano_formatura), ".. Insira o ano de formatura..: ", "\t>> Valor inserido invalido.");

    formando.endereco = ct_getline(200, ".. Insira o endereco..: ");
    formando.telefones[0] = ct_getline(50, ".. Insira o primeiro telefone..: ");
    formando.telefones[1] = ct_getline(50, ".. Insira o segundo telefone..: ");

    Lista = lista_inserir_fim(Lista, formando);
    return Lista;
}
