#include <stdio.h>
#include <stdlib.h>

int vetor[10], x, y;


void listar_vetor(int v[10]) { 
	for  (x = 0; x < 10; x++) {
		if (x < 9) {
			printf(" %d, ", v[x]);
		}
		if (x == 9) {
			printf(" %d \n", v[x]);
		}
	}
}


void bubble_Sort(int v[10]) {
	int i, j, aux;
	for(i = 10-1; i > 0; i--) {
		for(j = 0; j < i; j++) {
			if(v[j] > v[j+1]) {
				aux = v[j]; v[j] = v[j+1]; v[j+1] = aux; //troca
			}
		}
		printf("Bubble Sort: ");
		listar_vetor(v);
	}
}


void insertion_Sort(int v[10]){
	int i, j, x;
	for(i = 1; i < 10; i++) {
		x = v[i];
		j = i - 1;
		while(j >= 0 && v[j] > x) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = x;
		printf("Insertion Sort: ");
		listar_vetor(v);
	}
}


void selection_Sort(int v[10]){
    int i, j, aux, min;
    for(i = 0; i < 10-1; i++) {
        min = i;
        for(j = i+1; j < 10; j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }
		aux = v[i]; v[i] = v[min]; v[min] = aux; //troca
		printf("Selection Sort: ");
		listar_vetor(v);
    }
}


void main() {
	int oper;
	// Carregar vetor
	y = 10;
	printf("Vetor: ");
	for  (x = 0; x < 10; x++) {
		vetor[x] = y;
		y--;
		printf(" %d, ", vetor[x]);	
	}
	
	printf("\nSelecione a opcao desejada:\n1. Bubble sort \n2. Insertion Sort \n3. Selection Sort\n\n");
	scanf("%d", &oper);
	if (oper == 1) {
		bubble_Sort(vetor);
		oper = 0;
	}
	if (oper == 2) {
		insertion_Sort(vetor);
		oper = 0;
	}
	if (oper == 3) {
		selection_Sort(vetor);
		oper = 0;
	}
	printf("\n\nVetor Ordenado: ");
	listar_vetor(vetor);
	
}	
