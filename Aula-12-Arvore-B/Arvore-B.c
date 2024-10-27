#include <stdio.h>
#include <stdlib.h>

#define ORDEM 4

typedef struct NoArvoreB {
    int chaves[ORDEM - 1];
    struct NoArvoreB *filhos[ORDEM];
    int numChaves;
    int ehFolha;
} NoArvoreB;

NoArvoreB* criarNo(int ehFolha) {
    NoArvoreB* novoNo = (NoArvoreB*)malloc(sizeof(NoArvoreB));
    novoNo->ehFolha = ehFolha;
    novoNo->numChaves = 0;
    for (int i = 0; i < ORDEM; i++) {
        novoNo->filhos[i] = NULL;
    }
    return novoNo;
}

void percorrer(NoArvoreB* raiz) {
    if (raiz != NULL) {
        for (int i = 0; i < raiz->numChaves; i++) {
            if (!raiz->ehFolha) {
                percorrer(raiz->filhos[i]);
            }
            printf("%d ", raiz->chaves[i]);
        }
        if (!raiz->ehFolha) {
            percorrer(raiz->filhos[raiz->numChaves]);
        }
    }
}

NoArvoreB* buscar(NoArvoreB* raiz, int chave) {
    int i = 0;
    while (i < raiz->numChaves && chave > raiz->chaves[i]) {
        i++;
    }
    if (i < raiz->numChaves && chave == raiz->chaves[i]) {
        return raiz;
    }
    if (raiz->ehFolha) {
        return NULL;
    }
    return buscar(raiz->filhos[i], chave);
}

void dividirFilho(NoArvoreB* pai, int i, NoArvoreB* filho) {
    NoArvoreB* novoFilho = criarNo(filho->ehFolha);
    novoFilho->numChaves = ORDEM / 2 - 1;

    for (int j = 0; j < ORDEM / 2 - 1; j++) {
        novoFilho->chaves[j] = filho->chaves[j + ORDEM / 2];
    }

    if (!filho->ehFolha) {
        for (int j = 0; j < ORDEM / 2; j++) {
            novoFilho->filhos[j] = filho->filhos[j + ORDEM / 2];
        }
    }

    filho->numChaves = ORDEM / 2 - 1;

    for (int j = pai->numChaves; j >= i + 1; j--) {
        pai->filhos[j + 1] = pai->filhos[j];
    }

    pai->filhos[i + 1] = novoFilho;

    for (int j = pai->numChaves - 1; j >= i; j--) {
        pai->chaves[j + 1] = pai->chaves[j];
    }

    pai->chaves[i] = filho->chaves[ORDEM / 2 - 1];
    pai->numChaves++;
}

void inserirNaoCheio(NoArvoreB* raiz, int chave) {
    int i = raiz->numChaves - 1;

    if (raiz->ehFolha) {
        while (i >= 0 && chave < raiz->chaves[i]) {
            raiz->chaves[i + 1] = raiz->chaves[i];
            i--;
        }
        raiz->chaves[i + 1] = chave;
        raiz->numChaves++;
    } else {
        while (i >= 0 && chave < raiz->chaves[i]) {
            i--;
        }
        i++;
        if (raiz->filhos[i]->numChaves == ORDEM - 1) {
            dividirFilho(raiz, i, raiz->filhos[i]);
            if (chave > raiz->chaves[i]) {
                i++;
            }
        }
        inserirNaoCheio(raiz->filhos[i], chave);
    }
}

void inserir(NoArvoreB** raiz, int chave) {
    if (*raiz == NULL) {
        *raiz = criarNo(1);
        (*raiz)->chaves[0] = chave;
        (*raiz)->numChaves = 1;
    } else {
        if ((*raiz)->numChaves == ORDEM - 1) {
            NoArvoreB* novaRaiz = criarNo(0);
            novaRaiz->filhos[0] = *raiz;
            dividirFilho(novaRaiz, 0, *raiz);
            int i = 0;
            if (novaRaiz->chaves[0] < chave) {
                i++;
            }
            inserirNaoCheio(novaRaiz->filhos[i], chave);
            *raiz = novaRaiz;
        } else {
            inserirNaoCheio(*raiz, chave);
        }
    }
}

int main() {
    NoArvoreB* raiz = NULL;

    inserir(&raiz, 10);
    inserir(&raiz, 20);
    inserir(&raiz, 5);
    inserir(&raiz, 6);
    inserir(&raiz, 12);
    inserir(&raiz, 30);
    inserir(&raiz, 7);
    inserir(&raiz, 17);

    printf("Percorrendo a Arvore B construida: ");
    percorrer(raiz);
    printf("\n");

    int chave = 6;
    (buscar(raiz, chave) != NULL) ? printf("Chave %d esta presente\n", chave) : printf("Chave %d nao esta presente\n", chave);

    chave = 15;
    (buscar(raiz, chave) != NULL) ? printf("Chave %d esta presente\n", chave) : printf("Chave %d nao esta presente\n", chave);

    return 0;
}