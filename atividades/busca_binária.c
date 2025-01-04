#include <stdio.h>

int main(){
    int array[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int tamanho = sizeof(array) / sizeof(array[0]); // Retornar o tamanho da array
    int chave;

    printf("Digite o número que deseja buscar: ");
    scanf("%d", & chave);

    int resultado = buscaBinaria(array, tamanho, chave);

    return 0;
}
                // Parâmetros requerido para a função
int buscaBinaria(int array[], int tamanho, int chave){
    int incio = 0;
    int fim = tamanho - 1;

    while(incio <= fim){
        int meio = incio + ((fim - incio)/2);

        if(array[meio] == chave){
            return 1
        }
    }




    return -1; // Retorna -1 = chave não for encontrado
}