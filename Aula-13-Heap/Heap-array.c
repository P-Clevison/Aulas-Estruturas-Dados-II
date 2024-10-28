#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX_HEAP 100

int heap[TAMANHO_MAX_HEAP];
int tamanhoHeap = 0;

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapificarParaCima(int indice) {
    if (indice && heap[(indice - 1) / 2] < heap[indice]) {
        trocar(&heap[indice], &heap[(indice - 1) / 2]);
        heapificarParaCima((indice - 1) / 2);
    }
}

void heapificarParaBaixo(int indice) {
    int filhoEsquerdo = 2 * indice + 1;
    int filhoDireito = 2 * indice + 2;
    int maior = indice;

    if (filhoEsquerdo < tamanhoHeap && heap[filhoEsquerdo] > heap[maior])
        maior = filhoEsquerdo;

    if (filhoDireito < tamanhoHeap && heap[filhoDireito] > heap[maior])
        maior = filhoDireito;

    if (maior != indice) {
        trocar(&heap[indice], &heap[maior]);
        heapificarParaBaixo(maior);
    }
}

void inserir(int elemento) {
    if (tamanhoHeap == TAMANHO_MAX_HEAP) {
        printf("Heap overflow\n");
        return;
    }
    heap[tamanhoHeap] = elemento;
    heapificarParaCima(tamanhoHeap);
    tamanhoHeap++;
}

void deletarRaiz() {
    if (tamanhoHeap <= 0) {
        printf("Heap underflow\n");
        return;
    }
    heap[0] = heap[--tamanhoHeap];
    heapificarParaBaixo(0);
}

void exibirHeap() {
    for (int i = 0; i < tamanhoHeap; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    inserir(10);
    inserir(20);
    inserir(15);
    inserir(30);
    inserir(40);

    printf("Elementos do heap: ");
    exibirHeap();

    deletarRaiz();
    printf("Heap após deletar a raiz: ");
    exibirHeap();

    return 0;
}