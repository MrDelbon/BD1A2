#include <stdio.h>
#include <stdlib.h>

#define TAM 10000

int main()
{
	//variáveis
	long int vetor[TAM];
    long int aux, i, j;
    long int cont = 0;
    time_t t;

	srand((unsigned) time(&t));

	//preenche vetor
	for (i = 0; i<TAM; i++)
	{
		vetor [i] = rand() % 50000;
	}

	//mostra vetor na tela
	for (i = 0; i<TAM; i++)
	{
        if (i % 20 == 0)
        {
            printf("\n%li    ", vetor[i]);
		}
		else
		{
            printf("%li    ", vetor[i]);
		}
	}

	//bubble sort
	for (j = 0; j<TAM; j++)
	{
		for (i = 0; i<TAM-j; i++)
    	{

	    	if (vetor[i] > vetor[i+1])
	    	{
		        aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1]  = aux;
				cont++;
	    	}
    	}
   	}

   	//mostra vetor organizado na tela
   	printf("\n\n--------------------\n");
	for (i = 0; i<TAM; i++)
	{
		if (i % 20 == 0)
        {
            printf("\n%li    ", vetor[i]);
		}
		else
		{
            printf("%li    ", vetor[i]);
		}
	}
	printf("\n\n--------------------\n");
	printf("\nPara organizar o vetor, foram realizados %li movimentos", cont);
	return(0);
}
