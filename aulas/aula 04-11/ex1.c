#include <stdio.h>

int fatorial(int); 

int main(){
    int x;

    printf("Digite um número: ");
    scanf("%d", & x);

    printf("Fatorial de %d é %d.\n", x, fatorial(x));
}

int fatorial(int n){
    if(n<=1){
        return 1;
    } else{
        return n * fatorial(n - 1);
    }

    return 0;
}

