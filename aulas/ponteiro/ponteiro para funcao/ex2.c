#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int * const, const int);

#define TAM 10

int main(){
    int array[TAM];
    
    // Inicializa o gerador de números aleatórios com uma semente baseada no tempo atual
    srand(time(NULL));

    // Preenche o vetor com números aleatórios
    for(int k=0; k < TAM; k++){
        array[k] = rand() % 100; // Gera um número de 0 a 99
    }

    bubbleSort(int * const array, const int size)
    
    return 0;
}

void bubbleSort(int * const, const int TAM){

}