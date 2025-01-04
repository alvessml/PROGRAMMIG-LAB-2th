#include <stdio.h>

void display(int, int *);
void update(int *);

int main()
{
    int var = 15;
    int *ptr;

    ptr = &var;

    printf("Conteudo de var: %d\n", var);
    printf("Endereço de var: %p\n", &var);
    printf("Conteudo de ptr: %d\n", *ptr);
    printf("Endereço de ptr apontado: %p\n", ptr);
    printf("Endereço de ptr local: %p\n", &ptr);

    printf("\n");

    update(&var);
    printf("Conteudo de var: %d\n", var);
    printf("Endereço de var: %p\n", &var);
    printf("Conteudo de ptr atual: %d\n", *ptr);
    printf("Endereço de ptr atual apontado: %p\n", ptr);
    printf("Endereço de ptr atual local: %p\n", &ptr);

    // *ptr = 30;

    // printf("Conteudo de var: %d\n", var);
    // printf("Endereço de var: %p\n", &var);
    // printf("Conteudo de ptr atual: %d\n", *ptr);
    // printf("Endereço de ptr atual apontado: %p\n", ptr);
    // printf("Endereço de ptr atual local: %p\n", &ptr);

    // printf("\n");

    // printf("Function display:\n");
    // display(var, ptr);

    // printf("\n");

    // update(&var);
    // printf("Impressão da variável atualizada: \n");
    // display(var, ptr);

    return 0;
}

void display(int var, int *ptr)
{
    printf("Conteudo de var: %d\n", var);
    printf("Endereço de var: %p\n", &var);
    printf("Conteudo de ptr atual: %d\n", *ptr);
    printf("Endereço de ptr atual apontado: %p\n", ptr);
    printf("Endereço de ptr atual local: %p\n", &ptr);
}

void update(int *p)
{
    *p = *p + 1;
}