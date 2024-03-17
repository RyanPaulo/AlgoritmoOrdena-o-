#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100000

main() {
	clock_t inicio, final;
	double tempo_decorrido;
	int vetor[TAM], x, y, aux;
	x = 0;
	y = 0;
	aux = 0;
	printf("\nGerando um vetor com %d inteiros aleatorios:\n", TAM);
	for(x = 0; x < TAM; x++) {
		vetor[x] = rand() % 100;
		printf("%d\t", vetor[x]);
	}
	printf("\n\n %d numeros gerados, ENTER para Ordena: \n", TAM);
	getchar();

	inicio = clock();
	for(x = 0; x < TAM; x++) {
		for(y = 0; y < TAM - 1; y++){
			if(vetor[y] > vetor[y + 1]){
				aux = vetor[y];
				vetor[y] = vetor[y + 1];
				vetor[y + 1] = aux;
			}
		}
	}
	final = clock();
	tempo_decorrido = ((double) (final - inicio)) / CLOCKS_PER_SEC;
	
	printf("\nOrdena vetors: \n ");
	for(y = 0; y < TAM; y++){
		printf("%d\t", vetor[y], "\n");
	}
	printf("\n\nFoi Ordenado %d numeros inteiros com metodo BUBBLE SORT\n", TAM);
	
	printf("\nTempo de Ordenacao : %f milisegundos \n\n", tempo_decorrido);

}

