#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore AVL
typedef struct No {
    int chave;
    struct No *esq;
    struct No *dir;
    int altura;
} No;

// Função para obter a altura de um nó
int obter_altura(No* N) {
    if (N == NULL)
        return 0;
    return N->altura;
}

// Função para obter o valor máximo entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó
No* novoNo(int chave) {
    No* no = (No*)malloc(sizeof(No));
    no->chave = chave;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 1; // Novo nó é inicialmente adicionado como folha
    return(no);
}

// Função para rotacionar à dir a subárvore com raiz y
No* rotacaoDireita(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;

    // Realiza a rotação
    x->dir = y;
    y->esq = T2;

    // Atualiza as alturas
    y->altura = max(obter_altura(y->esq), obter_altura(y->dir)) + 1;
    x->altura = max(obter_altura(x->esq), obter_altura(x->dir)) + 1;

    // Retorna a nova raiz
    return x;
}

// Função para rotacionar à esq a subárvore com raiz x
No* rotacaoEsquerda(No* x) {
    No *y = x->dir;
    No *T2 = y->esq;

    // Realiza a rotação
    y->esq = x;
    x->dir = T2;

    // Atualiza as alturas
    x->altura = max(obter_altura(x->esq), obter_altura(x->dir)) + 1;
    y->altura = max(obter_altura(y->esq), obter_altura(y->dir)) + 1;

    // Retorna a nova raiz
    return y;
}

// Função para obter o fator de balanceamento de um nó
int obterBalanceamento(No* N) {
    if (N == NULL)
        return 0;
    return obter_altura(N->esq) - obter_altura(N->dir);
}

// Função para inserir um nó na árvore AVL
No* inserir(No* no, int chave) {
    // 1. Realiza a inserção normal na árvore binária de busca
    if (no == NULL)
        return(novoNo(chave));

    if (chave < no->chave)
        no->esq = inserir(no->esq, chave);
    else if (chave > no->chave)
        no->dir = inserir(no->dir, chave);
    else // Chaves duplicadas não são permitidas
        return no;

    // 2. Atualiza a altura deste nó ancestral
    no->altura = 1 + max(obter_altura(no->esq), obter_altura(no->dir));

    // 3. Obtém o fator de balanceamento deste nó ancestral para verificar se este nó ficou desbalanceado
    int balanceamento = obterBalanceamento(no);

    // Se este nó ficar desbalanceado, então existem 4 casos

    // Caso Esquerda-Esquerda
    if (balanceamento > 1 && chave < no->esq->chave)
        return rotacaoDireita(no);

    // Caso Direita-Direita
    if (balanceamento < -1 && chave > no->dir->chave)
        return rotacaoEsquerda(no);

    // Caso Esquerda-Direita
    if (balanceamento > 1 && chave > no->esq->chave) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    // Caso Direita-Esquerda
    if (balanceamento < -1 && chave < no->dir->chave) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    // Retorna o ponteiro do nó (inalterado)
    return no;
}

// Função para imprimir a árvore AVL (em ordem)
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

// Função para desalocar a memória da árvore AVL
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    No* raiz = NULL;

    // Inserindo nós na árvore AVL
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 17);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 24);
    raiz = inserir(raiz, 21);

    // Imprimindo a árvore AVL
    printf("Percurso em pre-ordem da arvore AVL construída e \n");
    preOrdem(raiz);

    // Liberando a memória alocada para a árvore AVL
    liberarArvore(raiz);

    return 0;
}
