#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct {
    No* raiz;
} Arvore;

Arvore* criarArvore() {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    return raiz;
}

No* buscarNo(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscarNo(raiz->esquerda, valor);
    } else {
        return buscarNo(raiz->direita, valor);
    }
}

void destruirArvore(No* raiz) {
    if (raiz != NULL) {
        destruirArvore(raiz->esquerda);
        destruirArvore(raiz->direita);
        free(raiz);
    }
}

void imprimirArvore(No* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirArvore(raiz->direita);
    }
}

#endif // ARVORE_H
