#include <stdio.h>
#include <stdlib.h>

int main() {
    // alocação estática de um vetor
    int v1[5];

    printf("endereco v1[0] = %d \n" , &v1);

    // alocação dinâmica de um vetor
    int* v2 = (int*)malloc(5, sizeof(int));

    printf("endereco v2[0] = %d \n" , &v2);

    return 0;
}