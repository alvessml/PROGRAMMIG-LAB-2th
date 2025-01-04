#include <stdio.h>

int main(){
    int i = 10;
    int j = 10;
    int *p, *q;
    p = &i;
    q = &j;
    printf("%p\n", &i);
    printf("%p\n", &j);
    printf("q antes: %d - %p\n", *q, &q);
    *q = *p;
    printf("%d - %p\n", *p, &p);
    printf("q antes: %d - %p\n", *q, &q);

    return 0;
}