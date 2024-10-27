#include <stdio.h>
#include <stdlib.h>

typedef enum { VERMELHO, PRETO } Cor;

typedef struct No {
    int valor;
    Cor cor;
    struct No *esquerda, *direita, *pai;
} No;

// Função para criar um novo nó
No *criarNo(int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->cor = VERMELHO;
    novoNo->esquerda = novoNo->direita = novoNo->pai = NULL;
    return novoNo;
}

// Função para rotação à esquerda
void rotacaoEsquerda(No **raiz, No *x) {
    No *y = x->direita;
    x->direita = y->esquerda;
    if (y->esquerda != NULL)
        y->esquerda->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL)
        *raiz = y;
    else if (x == x->pai->esquerda)
        x->pai->esquerda = y;
    else
        x->pai->direita = y;
    y->esquerda = x;
    x->pai = y;
}

// Função para rotação à direita
void rotacaoDireita(No **raiz, No *y) {
    No *x = y->esquerda;
    y->esquerda = x->direita;
    if (x->direita != NULL)
        x->direita->pai = y;
    x->pai = y->pai;
    if (y->pai == NULL)
        *raiz = x;
    else if (y == y->pai->direita)
        y->pai->direita = x;
    else
        y->pai->esquerda = x;
    x->direita = y;
    y->pai = x;
}

// Função para arrumar a árvore após a inserção
void inserirArrumar(No **raiz, No *k) {
    No *tio;
    while (k->pai && k->pai->cor == VERMELHO) {
        if (k->pai == k->pai->pai->esquerda) {
            tio = k->pai->pai->direita;
            if (tio && tio->cor == VERMELHO) {
                k->pai->cor = PRETO;
                tio->cor = PRETO;
                k->pai->pai->cor = VERMELHO;
                k = k->pai->pai;
            } else {
                if (k == k->pai->direita) {
                    k = k->pai;
                    rotacaoEsquerda(raiz, k);
                }
                k->pai->cor = PRETO;
                k->pai->pai->cor = VERMELHO;
                rotacaoDireita(raiz, k->pai->pai);
            }
        } else {
            tio = k->pai->pai->esquerda;
            if (tio && tio->cor == VERMELHO) {
                k->pai->cor = PRETO;
                tio->cor = PRETO;
                k->pai->pai->cor = VERMELHO;
                k = k->pai->pai;
            } else {
                if (k == k->pai->esquerda) {
                    k = k->pai;
                    rotacaoDireita(raiz, k);
                }
                k->pai->cor = PRETO;
                k->pai->pai->cor = VERMELHO;
                rotacaoEsquerda(raiz, k->pai->pai);
            }
        }
    }
    (*raiz)->cor = PRETO;
}

// Função para inserir um nó na árvore
void inserir(No **raiz, int valor) {
    No *novoNo = criarNo(valor);
    if (*raiz == NULL) {
        *raiz = novoNo;
    } else {
        No *x = *raiz, *y = NULL;
        while (x != NULL) {
            y = x;
            if (novoNo->valor < x->valor)
                x = x->esquerda;
            else
                x = x->direita;
        }
        novoNo->pai = y;
        if (novoNo->valor < y->valor)
            y->esquerda = novoNo;
        else
            y->direita = novoNo;
    }
    inserirArrumar(raiz, novoNo);
}

// Função para substituir um nó por outro
void transplantar(No **raiz, No *u, No *v) {
    if (u->pai == NULL)
        *raiz = v;
    else if (u == u->pai->esquerda)
        u->pai->esquerda = v;
    else
        u->pai->direita = v;
    if (v != NULL)
        v->pai = u->pai;
}

// Função para arrumar a árvore após a remoção
void removerArrumar(No **raiz, No *x) {
    No *irmao;
    while (x != *raiz && x->cor == PRETO) {
        if (x == x->pai->esquerda) {
            irmao = x->pai->direita;
            if (irmao->cor == VERMELHO) {
                irmao->cor = PRETO;
                x->pai->cor = VERMELHO;
                rotacaoEsquerda(raiz, x->pai);
                irmao = x->pai->direita;
            }
            if ((!irmao->esquerda || irmao->esquerda->cor == PRETO) && 
                (!irmao->direita || irmao->direita->cor == PRETO)) {
                irmao->cor = VERMELHO;
                x = x->pai;
            } else {
                if (!irmao->direita || irmao->direita->cor == PRETO) {
                    if (irmao->esquerda)
                        irmao->esquerda->cor = PRETO;
                    irmao->cor = VERMELHO;
                    rotacaoDireita(raiz, irmao);
                    irmao = x->pai->direita;
                }
                irmao->cor = x->pai->cor;
                x->pai->cor = PRETO;
                if (irmao->direita)
                    irmao->direita->cor = PRETO;
                rotacaoEsquerda(raiz, x->pai);
                x = *raiz;
            }
        } else {
            irmao = x->pai->esquerda;
            if (irmao->cor == VERMELHO) {
                irmao->cor = PRETO;
                x->pai->cor = VERMELHO;
                rotacaoDireita(raiz, x->pai);
                irmao = x->pai->esquerda;
            }
            if ((!irmao->direita || irmao->direita->cor == PRETO) && 
                (!irmao->esquerda || irmao->esquerda->cor == PRETO)) {
                irmao->cor = VERMELHO;
                x = x->pai;
            } else {
                if (!irmao->esquerda || irmao->esquerda->cor == PRETO) {
                    if (irmao->direita)
                        irmao->direita->cor = PRETO;
                    irmao->cor = VERMELHO;
                    rotacaoEsquerda(raiz, irmao);
                    irmao = x->pai->esquerda;
                }
                irmao->cor = x->pai->cor;
                x->pai->cor = PRETO;
                if (irmao->esquerda)
                    irmao->esquerda->cor = PRETO;
                rotacaoDireita(raiz, x->pai);
                x = *raiz;
            }
        }
    }
    x->cor = PRETO;
}

// Função para encontrar o nó com o menor valor
No *minimo(No *x) {
    while (x->esquerda != NULL)
        x = x->esquerda;
    return x;
}

// Função para remover um nó da árvore
void remover(No **raiz, No *z) {
    No *y = z, *x;
    Cor yCorOriginal = y->cor;
    if (z->esquerda == NULL) {
        x = z->direita;
        transplantar(raiz, z, z->direita);
    } else if (z->direita == NULL) {
        x = z->esquerda;
        transplantar(raiz, z, z->esquerda);
    } else {
        y = minimo(z->direita);
        yCorOriginal = y->cor;
        x = y->direita;
        if (y->pai == z) {
            if (x) x->pai = y;
        } else {
            transplantar(raiz, y, y->direita);
            y->direita = z->direita;
            if (y->direita) y->direita->pai = y;
        }
        transplantar(raiz, z, y);
        y->esquerda = z->esquerda;
        if (y->esquerda) y->esquerda->pai = y;
        y->cor = z->cor;
    }
    if (yCorOriginal == PRETO)
        removerArrumar(raiz, x);
}

// Função para imprimir a cor do nó
void imprimirCor(Cor cor) {
    if (cor == VERMELHO) {
        printf("VERMELHO");
    } else {
        printf("PRETO");
    }
}

// Função para imprimir a árvore em ordem
void imprimirArvore(No *raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);
        printf("Valor: %d, Cor: ", raiz->valor);
        imprimirCor(raiz->cor);
        printf("\n");
        imprimirArvore(raiz->direita);
    }
}

int main() {
    No *raiz = NULL;

    // Inserindo 7 valores na árvore
    inserir(&raiz, 10);
    inserir(&raiz, 20);
    inserir(&raiz, 30);
    inserir(&raiz, 15);
    inserir(&raiz, 25);
    inserir(&raiz, 5);
    inserir(&raiz, 1);

    // Imprimir a árvore
    imprimirArvore(raiz);
    printf("\n");

    // Removendo 1 valor da árvore
    No *n = raiz->direita->esquerda; // Nó com valor 25
    remover(&raiz, n);

    // Imprimir a árvore
    imprimirArvore(raiz);

    return 0;
}
