#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 200000

void mergeSort(int vetor[], int aux[], unsigned inicio, unsigned fim) {
	unsigned meio, i, j, k;

	if(inicio < fim ) {
		meio = (inicio + fim) / 2;
		mergeSort(vetor, aux, inicio, meio);
		mergeSort(vetor, aux, meio+1, fim);

		i = inicio;
		k = inicio;
		j = meio+1; 
		
		while ((i <= meio) && (j <= fim)) {
			if (vetor[i] < vetor[j]) {
				aux[k] = vetor[i]; 
				i++;
			}else {
			aux[k] = vetor[j];
			j++;
			}
			k++;
		}
		while (i <= meio) {
			aux[k] = vetor[i];
			i++;
			k++;
		}
		while (j <= fim) {
			aux[k] = vetor[j];
			j++;
			k++;
		}
		for (k = inicio; k <= fim; k++){
			vetor[k] = aux[k];
		}
		
	}
	
}

main() {
	clock_t inicio, final;
	double tempo_decorrido;
	int vetor[TAM], n, x, i;
	int aux[TAM];
	n = TAM;
	x = 0;

	printf("\nGerando um vetor com %d inteiros aleatorios:\n\n", TAM);
	for(x = 0; x < n; x++) {
		vetor[x]  = rand() % 100;
		printf("%d\t", vetor[x]);
	}
	printf("\n\n %d numeros gerados, ENTER para Ordena: \n", TAM);
	getchar();
	
	inicio = clock();
	mergeSort(vetor, aux, 0, TAM-1);
	final = clock();
	
	tempo_decorrido = ((double) (final - inicio)) / CLOCKS_PER_SEC;
	
	printf("\n\n\n Vetor ordenado por Merge Sort: \n");
	for(i = 0; i < n; i++){
		printf("%d\t", vetor[i]);
	}
	
	printf("\n\n Foi Ordenado %d numeros inteiros com metodo Merge Sort\n", TAM);
	
	printf("\nTempo de Ordenacao: %f milisegundos \n\n", tempo_decorrido);
}
