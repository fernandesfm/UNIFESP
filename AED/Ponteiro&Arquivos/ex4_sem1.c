//**************************************************************
// Autor: Felipe Fernandes Mendonça
// RA: 111788
// Turma: I
// Prof: Regina Coelho/Daniela Musa
//**************************************************************

/*EXERCÍCIO 1.4: Criando um programa que grava o nome de n pessoas em um arquivo texto.

- O usuário irá informar os nomes até digitar a palavra FIM.

- Após ter gravado os dados no arquivo, uma função que recebe como parâmetro um nome
retorna quantas pessoas existem com aquele mesmo nome no arquivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaração de um ponteiro para arquivo como variável global
FILE *arquivo;

//Verificação de quantos nomes presentes no arquivo são iguais ao nome passado como parâmetro
void Verifica_Nome(char nome[])
{
    //Declarando variáveis para obter o tamanho e contar a ocorrência de nomes iguais
    char texto[20];
    int cont=0, tam;

    //Abrindo arquivo para leitura
    arquivo = fopen("texto.txt", "r");

    //Se o arquivo não for encontrado, retorna um erro
    if(arquivo == NULL)
    {
        printf("Problema ao abrir o arquivo");
        exit(0);
    }

    //Enquanto o arquivo não chegar ao fim, lê-se o nome e realiza-se a verificação de igualdade
    while(!feof(arquivo))
    {
        fgets(texto, 20, arquivo);
        tam = strlen(texto);

        /*Se o texto obtido do arquivo não possuir ao menos um caractere e uma quebra de linha
        como último elemento, não ocorre a exclusão do \n*/
        if ((tam>0) && (texto[tam-1] == '\n'))
        {
            texto[--tam] = 0;
        }

        /*Se o texto obtido do arquivo não for igual ao parâmetro passado, não occore o
        acréscimo de cont*/
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
    //Declarando variáveis para armazenar os nomes no arquivo e o parâmetro para comparação
    char texto[20], nome[20];
    int i=0;

    //Abrindo arquivo para escrita
    arquivo = fopen("texto.txt", "w");

    //Se o arquivo não for encontrado, retorna um erro
    if(arquivo == NULL)
    {
        printf("Problema ao abrir o arquivo");
        exit(0);
    }

    //Enquanto o usuário não digitar "fim", armazena-se os nomes no arquivo
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

    //Lendo parâmetro para função de verificação
    scanf("%s", nome);

    printf("\n");

    //Fechando o aruqivo
    fclose(arquivo);

    //Chamando função de verificação
    Verifica_Nome(nome);

    return 0;
}
