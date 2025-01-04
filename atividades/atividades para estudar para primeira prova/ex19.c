#include <stdio.h>

int main(){
    int entrada, soma, subtracao, multiplicacao;
    float divisão;


    printf("Digite um número: ");
    scanf("%d", &entrada);

    printf("\nTabuada de soma: \n");
    for(int k=1; k <= 10; k++){
        soma = entrada+k;
        printf("%d + %d = %d\n", entrada, k, soma);
    }

    printf("\nTabuada de subtração: \n");
    for(int k=1; k <= 10; k++){
        subtracao = entrada-k;
        printf("%d - %d = %d\n", entrada, k, subtracao);
    }

    printf("\nTabuada de multiplicação: \n");
    for(int k=1; k <= 10; k++){
        multiplicacao = entrada*k;
        printf("%d x %d = %d\n", entrada, k, multiplicacao);
    }

    printf("\nTabuada de divisão: \n");
    for(int k=1; k <= 10; k++){
        float ent_div = entrada;
        divisão = entrada/k;
        printf("%.0f / %d = %.2f\n", ent_div, k, ent_div/k);
    }
    return 0;
}