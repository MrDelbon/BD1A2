#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

//variáveis globais
long int i, j, k;
long int vetor[TAM];

void merge(long int vetor[],long int l,long int m,long int r)
{
	//variáveis
    long int n1 = m - l + 1;
	long int n2 = r - m;
	
	//cria vetores temporários
    long int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = vetor[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        }
        else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long int vetor[],long int l,long int r)
{
    if (l < r) {

        long int m = l + (r - l) / 2;
        
        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);
  
        merge(vetor, l, m, r);
    }
}

int main()
{
    time_t t;
    
    srand((unsigned) time(&t));
    
    //preenche vetor
	for (i = 0; i<TAM; i++)
	{
		vetor [i] = rand() % 5000;
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
  
    mergeSort(vetor, 0, TAM - 1);
  
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
    return 0;
}
