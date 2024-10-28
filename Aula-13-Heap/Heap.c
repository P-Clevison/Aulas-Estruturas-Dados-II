#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX_HEAP 100

typedef struct {
    int tamanho;
    int dados[TAMANHO_MAX_HEAP];
} Heap;

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapificarParaCima(Heap *heap, int indice) {
    int indicePai = (indice - 1) / 2;
    if (indice && heap->dados[indicePai] < heap->dados[indice]) {
        trocar(&heap->dados[indicePai], &heap->dados[indice]);
        heapificarParaCima(heap, indicePai);
    }
}

void heapificarParaBaixo(Heap *heap, int indice) {
    int filhoEsquerdo = 2 * indice + 1;
    int filhoDireito = 2 * indice + 2;
    int maior = indice;

    if (filhoEsquerdo < heap->tamanho && heap->dados[filhoEsquerdo] > heap->dados[maior])
        maior = filhoEsquerdo;

    if (filhoDireito < heap->tamanho && heap->dados[filhoDireito] > heap->dados[maior])
        maior = filhoDireito;

    if (maior != indice) {
        trocar(&heap->dados[indice], &heap->dados[maior]);
        heapificarParaBaixo(heap, maior);
    }
}

void inserir(Heap *heap, int valor) {
    if (heap->tamanho == TAMANHO_MAX_HEAP) {
        printf("Heap overflow\n");
        return;
    }
    heap->dados[heap->tamanho] = valor;
    heapificarParaCima(heap, heap->tamanho);
    heap->tamanho++;
}

int extrairMaximo(Heap *heap) {
    if (heap->tamanho == 0) {
        printf("Heap underflow\n");
        return -1;
    }
    int valorMaximo = heap->dados[0];
    heap->dados[0] = heap->dados[--heap->tamanho];
    heapificarParaBaixo(heap, 0);
    return valorMaximo;
}

void deletar(Heap *heap, int indice) {
    if (indice < 0 || indice >= heap->tamanho) {
        printf("Índice fora do intervalo\n");
        return;
    }
    heap->dados[indice] = heap->dados[--heap->tamanho];
    heapificarParaBaixo(heap, indice);
}

void imprimirHeap(Heap *heap) {
    for (int i = 0; i < heap->tamanho; i++) {
        printf("%d ", heap->dados[i]);
    }
    printf("\n");
}

int main() {
    Heap heap;
    heap.tamanho = 0;

    inserir(&heap, 10);
    inserir(&heap, 20);
    inserir(&heap, 5);
    inserir(&heap, 30);

    printf("Elementos do Heap: ");
    imprimirHeap(&heap);

    printf("Máximo extraído: %d\n", extrairMaximo(&heap));
    printf("Elementos do Heap após extração: ");
    imprimirHeap(&heap);

    deletar(&heap, 1);
    printf("Elementos do Heap após deleção: ");
    imprimirHeap(&heap);

    return 0;
}