#include <stdio.h>
#include <stdlib.h>
//#define true 1
//#define false 0

//typedef int bool;

typedef struct NO {
    int chave; // Armazena o valor que vai estar contido no nó
    struct NO *esq, *dir;
} No;


