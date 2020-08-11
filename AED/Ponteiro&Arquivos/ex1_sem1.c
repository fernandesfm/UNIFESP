//**************************************************************
// Autor: Felipe Fernandes Mendonça
// RA: 111788
// Turma: I
// Prof: Regina Coelho/Daniela Musa
//**************************************************************

/*EXERCÍCIO 1.1: Criando estrutura e imprimindo dados*/

#include <stdio.h>
#include <stdlib.h>

// Declaração de estrutura do tipo "pessoa"
typedef struct pessoa
{
    char nome[20];
    int idade;
    int altura;
} tipo_pessoa;

int main ()
{
    // Alocando a estrutura dinamicamente sem cast (void *)
    tipo_pessoa *pessoa = malloc(sizeof(tipo_pessoa));

    if(pessoa == NULL)
    {
        printf("Memoria nao alocada");
        exit(0);
    }

    //Armazenando dados
    gets(pessoa->nome);
    scanf("%d", &pessoa->idade);
    scanf("%d", &pessoa->altura);

    //Imprimindo os dados armazenados
    printf("\n");
    puts(pessoa->nome);
    printf("%d\n", pessoa->idade);
    printf("%d\n", pessoa->altura);

    //Liberando a memória alocada
    free(pessoa);

    return 0;
}
