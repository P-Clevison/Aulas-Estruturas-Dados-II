#include <stdio.h>
#include <stdlib.h>

int vetor[10], x, y;


void listar_vetor(int v[]) { 
	for  (x = 0; x < 10; x++) {
		if (x < 9) {
			printf(" %d, ", v[x]);
		}
		if (x == 9) {
			printf(" %d \n", v[x]);
		}
	}
}


void bubble_Sort(int v[]) {
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


void insertion_Sort(int v[]){
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


void selection_Sort(int v[]){
    int i, j, aux, min;
    for(i = 0; i < 10-1; i++) {
        min = i;
        for(j = i+1; j < 10; j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }
		if (v[min] != v[i]) {
			aux = v[i]; v[i] = v[min]; v[min] = aux; //troca
		} else
		printf("Selection Sort: ");
		listar_vetor(v);
    }
}


void merge_Sort(int vetor, int inicio, int fim) {
	if (inicio < fim) {
		int meio = (inicio+fim)/2;
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio+1, fim);
		merge_Metades(vetor, inicio, meio, fim);
	}
}


void merge_Metades(int v[], int inicio, int meio, int fim) {
	int com1 = inicio, com2 = meio+1, comAux = 0, vetAux[10];
	while (com1<=meio && com2<=fim) {
		if (vetor[com1] <= vetor[com2]) {
			vetAux[comAux] = vetor[com1];
			com1++;
		} else {
			vetAux[comAux] = vetor[com2];
			com2++;
		}
		comAux++;
	}
	while (com1<=meio) { //Caso ainda haja elementos na primeira metade
		vetAux[comAux] = vetor[com1];
		comAux++;com1++;
	}
	while (com2<=fim) { //Caso ainda haja elementos na segunda metade
		vetAux[comAux] = vetor[com2];
		comAux++;com2++;
	}
	for (comAux=inicio; comAux<=fim; comAux++) { //Move os elementos de volta para o vetor original
		vetor[comAux] = vetAux[comAux-inicio];
	}
}

void quick_Sort(int v[], int inicio, int fim) {
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
	
	printf("\nSelecione a opcao desejada:\n1. Bubble sort \n2. Insertion Sort \n3. Selection Sort\n4. Merge Sort\n5. Quick Sort\n\n");
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
	if (oper == 4) {
		merge_Sort(vetor, 0, 10);
		oper = 0;
	}
	if (oper == 5) {
		quick_Sort(vetor, 0, 10);
		oper = 0;
	}
	printf("\n\nVetor Ordenado: ");
	listar_vetor(vetor);
	
}	
