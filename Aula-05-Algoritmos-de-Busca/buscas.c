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
	printf("Sorting...\n");
	int i, j, aux;
	for(i = len-1; i > 0; i--) {
		for(j = 0; j < i; j++) {
			if(v[j] > v[j+1]) {
				aux = v[j]; v[j] = v[j+1]; v[j+1] = aux; //troca
			}
		}
	}
}


int linear_Search(int arr[], int len, int target) {
	int run_cnt = 0;
	for (int i = 0; i < len; i++) {
		run_cnt++;
		if (arr[i] == target) {
			printf("Foram necessarias %d execucoes para encontrar o valor\n", run_cnt);
			return i; // Retorna o índice do elemento encontrado
		}
	}
	return -1; // Retorna -1 se o elemento não for encontrado
}


int binary_Search(int arr[], int len, int target) {
	int left = 0;
	int right = len - 1;
	int run_cnt = 0;
	
	while (left <= right) {
		run_cnt++;
		int mid = left + (right - left) / 2;
		
		if (arr[mid] == target) {
			printf("Foram necessarias %d execucoes para encontrar o valor\n", run_cnt);
			return mid; // Retorna o índice do elemento encontrado
		}
		
		if (arr[mid] < target) {
			left = mid + 1; // Ignora a metade esquerda
		} else {
			right = mid - 1; // Ignora a metade direita
		}
	}
	return -1; // Retorna -1 se o elemento não for encontrado
}


int main() {
	int oper = 0;
	int lenght = 10;
	int array[10];
	int key, result;

	srand(time(NULL));
	fill_Random(array, lenght, lenght * 2);
	list_array(array, lenght);
	
	while (oper == 0) {
		printf("\nSelecione a opcao desejada:\n1. Busca linear \n2. Busca binaria\n\n3. Recarregar vetor\n\n");
		scanf("%d", &oper);

		if (oper >= 1 && oper <= 2) {
			printf("\nDigite o valor a ser buscado: ");
			scanf("%d", &key);
		}
		
		if (oper == 1) {
			result = linear_Search(array, lenght, key);
			if (result != -1) {
				printf("Elemento encontrado na posicao: %d\n", result);
			} else {
				printf("Elemento nao encontrado.\n");
			}
			oper = 0;
		}
		if (oper == 2) {
			bubble_Sort(array, lenght);
			list_array(array, lenght);
			result = binary_Search(array, lenght, key);
			if (result != -1) {
				printf("Elemento encontrado na posicao: %d\n", result);
			} else {
				printf("Elemento nao encontrado.\n");
			}
			oper = 0;
		}
        if (oper == 3) {
            fill_Random(array, lenght, lenght * 2);
            list_array(array, lenght);
            bubble_Sort(array, lenght);
            list_array(array, lenght);
            oper = 0;
        }
	}

	return 0;
}