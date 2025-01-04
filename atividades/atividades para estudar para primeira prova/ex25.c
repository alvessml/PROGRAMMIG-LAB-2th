#include <stdio.h>

int fatorial(int );

int main(){
    int entrada, resultado;

    printf("Digite um número para saber seu fatorial: ");
    scanf("%d", & entrada);

    resultado = fatorial(entrada);

    printf("Fatorial de %d é %d\n", entrada, resultado);

    return 0;
}

int fatorial(int x){
    int fat = 1;
    for(int k = x; k > 0; k--){
        fat = fat * k; 
    }
    return fat;
}