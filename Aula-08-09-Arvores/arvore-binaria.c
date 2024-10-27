#include "Arvore.h" // Inclui o arquivo de cabeçalho que contém as definições da árvore

int main() {
    Arvore* arvore = criarArvore(); // Cria uma nova árvore na memória
    int valores[] = {50, 30, 70, 20, 40, 60}; 
    for (int i = 0; i < 6; i++) {
        arvore->raiz = inserirNo(arvore->raiz, valores[i]); // Insere cada valor na árvore
    }

    printf("Árvore em ordem: ");
    imprimirArvore(arvore->raiz);
    printf("\n");

    int valorParaBuscar = 40; // Valor a ser buscado na árvore
    No* resultado = buscarNo(arvore->raiz, valorParaBuscar);
    if (resultado != NULL) {
        printf("Valor %d encontrado na arvore.\n", valorParaBuscar);
    } else {
        printf("Valor %d nao encontrado na arvore.\n", valorParaBuscar);
    }

    destruirArvore(arvore->raiz); // Destrói a árvore
    free(arvore); // Libera a memória alocada para a árvore

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
