#include <stdio.h>
#include <string.h>


int main(){
    char vetor[] = "Hello";
    char *str = vetor;

    *(str + 2) = 'f';
    vetor[3] = 'i';

    printf("%s\n", vetor);
    printf("%s\n", str);
    printf("%p\n", vetor);
    printf("%p\n", str);

    return 0;
}