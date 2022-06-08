#include <stdio.h>
#include <stdlib.h>

#define TAM 10000

int main () 
{
	//variáveis
	long int vetor[TAM];
    long int pos_min, aux, i, j;
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
	
    //selection sort
    for(i=0; i < TAM-1; i++) 
    {
        pos_min = i;
        for (j=i+1; j < TAM; j++) 
        {
            if (vetor[j] < vetor[pos_min]) 
            {
                pos_min = j;
            }
        }
        if (pos_min != i) 
        {
            aux = vetor[i];
            vetor[i] = vetor[pos_min];
            vetor[pos_min] = aux;
            cont++;
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
	printf("\nPara organizar o vetor, foram realizados %i movimentos", cont);
	return(0);
}
