#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 200000

int dividir(int vetor[], int l, int r) {
	
	int aux, i;
	int cont = l;

	for( i=l+1; i<=r; i++){
	
		if( vetor[i] < vetor[l] ) {
			cont++;
			aux = vetor[i];
			vetor[i] = vetor[cont];
			vetor[cont] = aux;
		
		}
	}
	aux = vetor[l];
	vetor[l] = vetor[cont];
	vetor[cont] = aux;
	
	return cont;

}


void quick(int vetor[], int l, int r){
	
	int pos;
	
	if( l < r) {
		pos = dividir(vetor,l,r);
		quick(vetor, l, pos - 1);
		quick(vetor, pos + 1, r);
	}
	
}

int main() {
	
	int vetor[TAM], x, i;
	int n = TAM;

	
	x = 0;
	
	printf("\n Gerando um vetor com %d inteiros aleatorios:\n", TAM);
	for(x = 0; x < TAM; x++) {
		vetor[x] = rand() % 100; 
		printf("%d\t", vetor[x]);
		
	}
	printf("\n\n %d numeros gerados, ENTER para Ordena: \n", TAM);
	getchar();
	clock_t inicio, final;
	double tempo;
	
	inicio = clock();
	quick(vetor, 0, n - 1);
	final = clock();
	
	tempo = ((double) (final - inicio)) / CLOCKS_PER_SEC;
	

	
	printf("\n\n\nVetor Ordenado por Guick Sort: \n");
	
	
	for(i = 0; i < n; i++){
		printf("%d\t", vetor[i]);
		
	}
	
	printf("\n\nFoi Ordenado %d numeros inteiros com metotodo QUICK SORT\n", TAM);
	printf("\n Tempo de Ordeenacao: %f milisegundos\n", tempo);
	
}
