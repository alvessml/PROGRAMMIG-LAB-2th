#include <stdio.h>
void apply(void (*)(int), int);
void imprime(int);

int main(){
    apply(imprime, 10);

    return 0;
}

void apply(void (*func_pointer)(int), int x){
    func_pointer(x); // ou: (*func_pointer)(x);
}

void imprime(int a){
    printf("%d\n", a);
}