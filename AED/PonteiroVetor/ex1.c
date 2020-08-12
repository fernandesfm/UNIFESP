//**************************************************************
// Autor: Felipe Fernandes Mendonça
// RA: 111788
// Turma: I
// Prof: Regina Coelho/Daniela Musa
//**************************************************************

/*EXERCÍCIO: Mostrar o vencedor de uma eleição.

- O programa deve ler os votos de cada pessoa até que a entrada seja um valor
inteiro negativo.

- Considerando que o número de candidatos é N, o voto de cada um deverá ser um
número inteiro entre 1 e N que referencia um candidato.

- Em caso de empate o candidato que é referenciado pelo maior valor inteiro deverá
ser o vencedor da eleição.

Ao final o programa deverá imprimir o número referente ao candidato com mais votos,
ou seja, o vencedor da eleição.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declarando variáveis
    int voto, N, *v, i, verifica=0;

    //Obtendo o número de candidatos
    scanf("%d", &N);

    //Armazenando N+1 posições para conseguir manipular os índices de 1 a N
    v = malloc((N+1) * sizeof(int));

    //Caso não consiga alocar, retorna uma mensagem de erro
    if (v==NULL)
    {
        printf("Nao foi possivel alocar o vetor\n");
        exit(0);
    }

    //Atribuindo o valor 0 a todos os elementos do vetor
    for(i=1; i<N+1; i++)
    {
        *(v+i) = 0;
    }

    /*Armazenando valores até que a entrada seja um número negativo. Caso o usuário digite
    o valor 0 ou algum maior que N, a leitura é feita novamente até obter um número válido*/
    while(1)
    {
        scanf("%d", &voto);

        if(voto == 0 || voto > N)
        {
            printf("Voto invalido! Para que o voto seja valido, digite um numero entre 1 e %d:\n", N);
        }

        if(voto < 0)
        {
            break;
        }

        if(voto > 0 && voto <= N)
        {
            *(v+voto) += 1;
        }
    }

    /*Caso não exista nenhum voto válido a algum candidato, o programa se encerra retornando
    uma mensagem informando sobre o ocorrido*/
    for(i=1; i<N+1; i++)
    {
        if(*(v+i) == 0)
        {
            verifica++;
        }
    }

    if(verifica == N)
    {
        printf("\nNao houveram votos validos.\n");
        exit(1);
    }

    //Atribuição de valores a variáveis auxiliares para verificação do mais votado
    int aux = *(v+1), indice=1;

    for(i=0; i<N; i++)
    {
        /*Comparação elemento a elememento. Caso o valor seguinte seja maior que o atual, atualiza-se
        a variável aux e indice. Caso sejam iguais, realiza-se a comparação dos índices, priorizando
        o maior, seguindo o enunciado*/
        if(aux < *(v+(i+1)))
        {
            aux = *(v+(i+1));
            indice = i+1;
        }

        if(aux == *(v+(i+1)))
        {
            if(indice < i+1)
            {
                aux = *(v+(i+1));
                indice = i+1;
            }
        }
    }

    //Imprimindo a mensagem do vencedor da eleição
    printf("\nO vencedor foi o candidato %d com %d voto(s).\n", indice, aux);

    //Liberando a memória alocada
    free(v);

    return 0;
}
