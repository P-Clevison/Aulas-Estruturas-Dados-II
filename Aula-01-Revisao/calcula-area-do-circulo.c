//Código em linguagem C
#include <stdio.h>

int main() {
    const double Pi = 3.141592;
    double raio, area;
    float arr[3];
    int i,j;

    for (i = 0; i < 3; i++)
    {
        printf("\r\nDigite o raio do circulo:");
        scanf("%lf", &raio);
        if (raio > 0) {
            printf("\nCalculando a area do circulo com raio = %lf", raio);
            // Formula area = Pi * raio^2
            area = Pi * raio * raio;
            printf("\nArea = %lf \n", area);

        } else {
            printf("Impossivel calcular a area do circulo com raio informado. O valor deve ser positivo");
        }
        arr[i] = area;
    }

    for (j = 0; j < 3; j++)
    {
        print(arr[i]);
    }
    return 0;
}