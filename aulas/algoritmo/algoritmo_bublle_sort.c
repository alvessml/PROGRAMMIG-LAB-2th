#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXVETOR 10

void preencherNumArray(int *);
void printNumArray(int *);


int main(){
    int array[MAXVETOR];

    preencherNumArray(array);

    printf("Vetor gerado aleatoriamente: ");
    printNumArray(array);

    return 0;
}

void preencherNumArray(int *array){
    srand(time(NULL));

    for(int k=0; k < MAXVETOR; k++){
        array[k] = rand() % 100;
    }
}

void printNumArray(int *array){
    for(int k=0; k < MAXVETOR; k++){
        printf("%d ", array[k]);
    }
    printf("\n");
}