#include <stdio.h>

int soma(int, int);

int main(){
    int entrada1, entrada2, resultado;


    printf("Digite um número: ");
    scanf("%d", & entrada1);

    printf("Digite outro número: ");
    scanf("%d", & entrada2);

   resultado = soma(entrada1, entrada2);

    printf("A soma de %d + %d = %d\n", entrada1, entrada2, resultado);

    return 0;
}


 int soma(int x, int y){
    int soma = 0;
    soma = x + y;
    return soma;
} 
