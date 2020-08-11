//**************************************************************
// Autor: Felipe Fernandes Mendon�a
// RA: 111788
// Turma: I
// Prof: Regina Coelho/Daniela Musa
//**************************************************************

/*EXERC�CIO 1.2: Criando estrutura e imprimindo dados atrav�s de uma fun��o*/

#include <stdio.h>
#include <stdlib.h>

// Declara��o de estrutura do tipo "pessoa"
typedef struct pessoa
{
    char nome[20];
    int idade;
    int altura;
} tipo_pessoa;

//Impress�o dos dados armazenados
void Imprime_Dados(tipo_pessoa *pessoa)
{
    printf("\n");
    puts(pessoa->nome);
    printf("%d\n", pessoa->idade);
    printf("%d\n", pessoa->altura);
}

int main ()
{
    // Alocando a estrutura dinamicamente sem cast (void *)
    tipo_pessoa *pessoa = malloc(sizeof(tipo_pessoa));

    /*Se n�o houver mem�ria dispon�vel o suficiente, retorna uma mensagem
    de erro*/
    if(pessoa == NULL)
    {
        printf("Memoria nao alocada");
        exit(0);
    }

    //Armazenando dados
    gets(pessoa->nome);
    scanf("%d", &pessoa->idade);
    scanf("%d", &pessoa->altura);

    //Chamando fun��o de impress�o
    Imprime_Dados(pessoa);

    //Liberando a mem�ria alocada
    free(pessoa);

    return 0;
}
