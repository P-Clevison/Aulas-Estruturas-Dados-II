#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    char d;

    a = 10;
    b = 20;
    c = a + b;
    d = "UNASP";

    printf("a = %d \n" , a);
    printf("b = %d \n" , b);
    printf("c = %d \n\n" , c);
    printf("d = %c \n" , d);

    printf("&a = %p \n" , &a);
    printf("&b = %p \n" , &b);
    printf("&c = %p \n" , &c);
    printf("&d = %p \n" , &d);
    
    return 0;
}