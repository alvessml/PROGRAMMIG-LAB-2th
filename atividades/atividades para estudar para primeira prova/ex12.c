#include <stdio.h>

int main(){
    int entrada;

    printf("Digite um ano qualquer: ");
    scanf("%d", & entrada);

    if(entrada % 4 == 0) {
        printf("O ano %d é bissexto.\n", entrada);
    } else{
        printf("O ano %d NÃO é bissexto.\n", entrada);
    }

    return 0;
}

