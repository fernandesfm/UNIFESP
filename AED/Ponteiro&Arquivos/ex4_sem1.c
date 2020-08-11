//**************************************************************
// Autor: Felipe Fernandes Mendon�a
// RA: 111788
// Turma: I
// Prof: Regina Coelho/Daniela Musa
//**************************************************************

/*EXERC�CIO 1.4: Criando um programa que grava o nome de n pessoas em um arquivo texto.

- O usu�rio ir� informar os nomes at� digitar a palavra FIM.

- Ap�s ter gravado os dados no arquivo, uma fun��o que recebe como par�metro um nome
retorna quantas pessoas existem com aquele mesmo nome no arquivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declara��o de um ponteiro para arquivo como vari�vel global
FILE *arquivo;

//Verifica��o de quantos nomes presentes no arquivo s�o iguais ao nome passado como par�metro
void Verifica_Nome(char nome[])
{
    //Declarando vari�veis para obter o tamanho e contar a ocorr�ncia de nomes iguais
    char texto[20];
    int cont=0, tam;

    //Abrindo arquivo para leitura
    arquivo = fopen("texto.txt", "r");

    //Se o arquivo n�o for encontrado, retorna um erro
    if(arquivo == NULL)
    {
        printf("Problema ao abrir o arquivo");
        exit(0);
    }

    //Enquanto o arquivo n�o chegar ao fim, l�-se o nome e realiza-se a verifica��o de igualdade
    while(!feof(arquivo))
    {
        fgets(texto, 20, arquivo);
        tam = strlen(texto);

        /*Se o texto obtido do arquivo n�o possuir ao menos um caractere e uma quebra de linha
        como �ltimo elemento, n�o ocorre a exclus�o do \n*/
        if ((tam>0) && (texto[tam-1] == '\n'))
        {
            texto[--tam] = 0;
        }

        /*Se o texto obtido do arquivo n�o for igual ao par�metro passado, n�o occore o
        acr�scimo de cont*/
        if(strcmp(texto, nome) == 0)
        {
            cont++;
        }
    }

    printf("Existem %d pessoas com o nome %s no arquivo.\n", cont, nome);

    //Fechando o arquivo
    fclose(arquivo);
}

int main ()
{
    //Declarando vari�veis para armazenar os nomes no arquivo e o par�metro para compara��o
    char texto[20], nome[20];
    int i=0;

    //Abrindo arquivo para escrita
    arquivo = fopen("texto.txt", "w");

    //Se o arquivo n�o for encontrado, retorna um erro
    if(arquivo == NULL)
    {
        printf("Problema ao abrir o arquivo");
        exit(0);
    }

    //Enquanto o usu�rio n�o digitar "fim", armazena-se os nomes no arquivo
    while(1)
    {
        scanf("%s", texto);

        if((strcmp(texto,"FIM") == 0) || (strcmp(texto,"fim") == 0))
        {
            break;
        }
        else
        {
            if(i==0)
            {
                fprintf(arquivo, "%s", texto);
            }
            else
            {
                fprintf(arquivo, "\n%s", texto);
            }
        }

        i++;
    }

    //Lendo par�metro para fun��o de verifica��o
    scanf("%s", nome);

    printf("\n");

    //Fechando o aruqivo
    fclose(arquivo);

    //Chamando fun��o de verifica��o
    Verifica_Nome(nome);

    return 0;
}
