#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXVETOR 10

void preencherNumArray(int *);
void bubbleSort(int, int *);
void printNumArray(int *);


int main(){
    int array[MAXVETOR];

    preencherNumArray(array);

    int n = sizeof(array) / sizeof(array[0]);
    bubbleSort(n, *array);


    return 0;
}

void preencherNumArray(int *array){
    srand(time(NULL));

    for(int k=0; k < MAXVETOR; k++){
        array[k] = rand() % 100;
    }
}

void bubbleSort(int n, int *array){
    int temp;

    4 3 2
    3 4 2
                 1 < 2
    for(int i=0; i < n - 1; i++){
                  1  1 < 1
        for(int j=0; j < n - 1 - i; j++){
                4            3
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void printNumArray(int *array){
    for(int k=0; k < MAXVETOR; k++){
        printf("%d ", array[k]);
    }
    printf("\n");
}

