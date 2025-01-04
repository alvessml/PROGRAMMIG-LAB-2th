#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printArray(int, int);

int main(){
    int size = 15;
    int array[size];
    
    srand(time(NULL));
    for(int k=0; k < size; k++){
        array[k] = rand() % 100;
    }

    printArray(size, array);
    
    return 0;
}

int printArray(int size, int array){
    int i=0;
    for(i; i<size; i++){
        printf("%d, ", array[i]);
    }
}