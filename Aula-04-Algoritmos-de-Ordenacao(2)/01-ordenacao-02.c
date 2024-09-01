#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_Random(int v[], int len, int max) {
	for (int i = 0; i < len; i++) {
		v[i] = (rand() % max) + 1;
	}
}


void list_array(int v[], int len) { 
	for (int x = 0; x < len; x++) {
		if (x < len - 1) {
			printf(" %d, ", v[x]);
		} else {
			printf(" %d \n", v[x]);
		}
	}
}


void bubble_Sort(int v[], int len) {
	int i, j, aux;
	for(i = len-1; i > 0; i--) {
		for(j = 0; j < i; j++) {
			if(v[j] > v[j+1]) {
				aux = v[j]; v[j] = v[j+1]; v[j+1] = aux; //troca
			}
		}
		printf("Bubble Sort: ");
		list_array(v, len);
	}
}


void insertion_Sort(int v[], int len){
	int i, j, x;
	for(i = 1; i < len; i++) {
		x = v[i];
		j = i - 1;
		while(j >= 0 && v[j] > x) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = x;
		printf("Insertion Sort: ");
		list_array(v, len);
	}
}


void selection_Sort(int v[], int len){
    int i, j, aux, min;
    for(i = 0; i < len-1; i++) {
        min = i;
        for(j = i+1; j < len; j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }
		if (v[min] != v[i]) {
			aux = v[i]; v[i] = v[min]; v[min] = aux; //troca
		} else
		printf("Selection Sort: ");
		list_array(v, len);
    }
}


void merge_Halfs(int v[], int begin, int midd, int end) {
	int com1 = begin, com2 = midd + 1, comAux = 0;
    int *vetAux = (int *)malloc((end - begin + 1) * sizeof(int));
	while (com1 <= midd && com2 <= end) {
		if (v[com1] <= v[com2]) {
			vetAux[comAux] = v[com1];
			com1++;
		} else {
			vetAux[comAux] = v[com2];
			com2++;
		}
		comAux++;
	}
	while (com1 <= midd) { // Caso ainda haja elementos na primeira metade
		vetAux[comAux] = v[com1];
		comAux++;
		com1++;
	}
	while (com2 <= end) { // Caso ainda haja elementos na segunda metade
		vetAux[comAux] = v[com2];
		comAux++;
		com2++;
	}
	for (comAux = begin; comAux <= end; comAux++) { // Move os elementos de volta para o vetor original
		v[comAux] = vetAux[comAux - begin];
	}
    free(vetAux);
}


void merge_Sort(int v[], int begin, int end) {
	if (begin < end) {
		int midd = (begin + end) / 2;
		merge_Sort(v, begin, midd);		
		merge_Sort(v, midd + 1, end);
		merge_Halfs(v, begin, midd, end);
	}
	printf("\nMerge Sort: ");
	list_array(v, end);
}


int partition(int v[], int begin, int end) {
    int pivot = v[end];
    int i = (begin - 1);
    for (int j = begin; j <= end - 1; j++) {
        if (v[j] < pivot) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[end];
    v[end] = temp;
    return (i + 1);
}


void quick_Sort(int v[], int begin, int end) {
    if (begin < end) {
        int pi = partition(v, begin, end);
        quick_Sort(v, begin, pi - 1);
        quick_Sort(v, pi + 1, end);
    }
	printf("\nQuick Sort: ");
	list_array(v, end);
}


void main() {
	int oper = 0;
	int lenght = 10;
	int array[10];
	srand(time(NULL));
	fill_Random(array, lenght, lenght * 2);
	list_array(array, lenght);
	
	while (oper == 0) {
		printf("\nSelecione a opcao desejada:\n1. Bubble sort \n2. Insertion Sort \n3. Selection Sort\n4. Merge Sort\n5. Quick Sort\n\n6. Preencher vetor\n\n");
		scanf("%d", &oper);
		if (oper == 1) {
			bubble_Sort(array, lenght);
			oper = 0;
		}
		if (oper == 2) {
			insertion_Sort(array, lenght);
			oper = 0;
		}
		if (oper == 3) {
			selection_Sort(array, lenght);
			oper = 0;
		}
		if (oper == 4) {
			merge_Sort(array, 0, lenght - 1);
			oper = 0;
		}
		if (oper == 5) {
			quick_Sort(array, 0, lenght - 1);
			oper = 0;
		}
		if (oper == 6) {
			fill_Random(array, lenght, lenght * 2);
			oper = 0;
		}
	}
}