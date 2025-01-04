#include <stdio.h>

int main(){
    unsigned char entrada;

    printf("Digite um caractere: ");
    scanf("%c", &entrada);

    printf("O caractere digitado %c em ASCII é %d\n", entrada, entrada);

    return 0;
}
