#include <stdio.h>

void adicionaMaisUmValorArray(int arrayantiga[], int arraynova[], int, int);

int main(){
    int tamanho = 10;
    int array[tamanho];

    printf("Array criada: ");
    for(int k=0; k < tamanho; k++){
        array[k] = k+1;
    }

    for(int k=0; k < tamanho; k++){
        printf("%d ", array[k]);
    }

    printf("\nArray criada invertida: ");
    for(int k=0; k < tamanho; k++){
        array[k] = tamanho - k;
    }

    for(int k=0; k < tamanho; k++){
        printf("%d ", array[k]);
    }

    printf("\n\nAdicionando o número 77 no começo: ");
    int arraynova[tamanho+1];
    adicionaMaisUmValorArray(array, arraynova, tamanho, 77);
    for(int k=0; k < tamanho+1; k++){
        printf("%d ", arraynova[k]);
    }

    return 0;
}

void adicionaMaisUmValorArray(int arrayantiga[], int arraynova[], int tamanho, int novoValor){
    for(int k = 1; k < tamanho+1; k++){
        arraynova[k] = arrayantiga[k-1];
    }
    arraynova[0] = novoValor;
}