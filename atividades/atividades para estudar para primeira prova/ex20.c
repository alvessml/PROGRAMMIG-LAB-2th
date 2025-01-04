#include <stdio.h>

#define TAM 100
 
int main(){
    char string[TAM];

    printf("Digite um caractere qualquer: ");
    scanf("%s", string);

    int tam = 0;
    int x = 0;
    while(string[x] != '\0'){
        tam += 1;        
        x += 1;
    }

    printf("Sua string digitada tem o tamnho de %d caracteres.\n", tam);

    return 0;
}