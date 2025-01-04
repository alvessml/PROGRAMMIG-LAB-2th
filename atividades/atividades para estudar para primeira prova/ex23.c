#include <stdio.h>

int main(){ 
    int entrada;

    printf("Digite alguns números (0 - para parar): ");
    do {
        scanf("%d", & entrada);
        if (entrada == 0){
            break;
        }
    } while (entrada != 0);
    
    return 0;
}