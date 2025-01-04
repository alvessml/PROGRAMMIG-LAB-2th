#include <stdio.h>

int main(){
    int num;

    printf("Digite um número qualquer: ");
    scanf("%d", &num);

    for(int k = sizeof(int) * 8 - 1; k >=0; k--){
        printf("%d", (num >> k) & 1);
    }

    return 0;
}