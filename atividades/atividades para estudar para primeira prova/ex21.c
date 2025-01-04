#include <stdio.h>

int main(){
    int entrada;

    printf("Digite um número qualquer: ");
    scanf("%d", &entrada);

    int divisores = 0;
    for(int k = entrada; k > 0; k--){
        if(entrada % k == 0){
            divisores += 1;
        }
    } 

    if(divisores == 2){
        printf("O número %d é primo.\n", entrada);
    } else{
        printf("O número %d NÃO é primo.\n", entrada);
    }

    return 0;
}