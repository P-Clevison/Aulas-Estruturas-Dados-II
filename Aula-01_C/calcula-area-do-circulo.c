//Código em linguagem C
#include <stdio.h>

int main() {
    const double Pi = 3.141592;
    double raio;
    float arr[3];
 
    printf("Digite o raio do circulo:");
    scanf("%lf", &raio);
    if (raio > 0) {
        printf("\nCalculando a area do circulo com raio = %lf", raio);
        // Formula area = Pi * raio^2
        double area = Pi * raio * raio;
        printf("\n\nArea = %lf", area);

    } else {
        printf("Impossivel calcular a area do circulo com raio informado. O valor deve ser positivo");
    } 
    
    return 0;
}