//**************************************************************
// Autor: Felipe Fernandes Mendonça
// RA: 111788
// Turma: I
// Prof: Regina Coelho/Daniela Musa
//**************************************************************

/*EXERCÍCIO 1.3: Criando vetor de estruturas e imprimindo dados através de uma função*/

#include <stdio.h>
#include <stdlib.h>

// Declaração de estrutura do tipo "pessoa"
typedef struct pessoa
{
    char nome[20];
    int idade;
    int altura;
} tipo_pessoa;

//Impressão dos dados armazenados
void Imprime_Dados(tipo_pessoa *pessoa)
{
    printf("\n");
    puts(pessoa->nome);
    printf("%d\n", pessoa->idade);
    printf("%d\n", pessoa->altura);
}

int main ()
{
    //Declarando vetor de estruturas
    tipo_pessoa *pessoa[100];

    //Declarando variáveis para obter o tamanho do vetor
    int i, n;

    scanf("%d", &n);

    //Alocando a estrutura dinamicamente sem cast (void *) e armazenando dados
    for(i=0; i<n; i++)
    {
        pessoa[i] = malloc(sizeof(tipo_pessoa));

        /*Se não houver memória disponível o suficiente, retorna uma mensagem
        de erro*/
        if(pessoa == NULL)
        {
            printf("Memoria não alocada");
            exit(0);
        }

        scanf("%s", &pessoa[i]->nome);
        scanf("%d", &pessoa[i]->idade);
        scanf("%d", &pessoa[i]->altura);
    }

    //Chamando função de impressão
    for(i=0; i<n; i++)
    {
        Imprime_Dados(pessoa[i]);
    }

    //Liberando a memória alocada
    for(i=0; i<n; i++)
    {
        free(pessoa[i]);
    }

    return 0;
}
