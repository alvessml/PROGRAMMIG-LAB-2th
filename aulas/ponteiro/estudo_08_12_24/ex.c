#include <stdio.h>

int main(){
    int i = 10;
    int *p, *q;
    p = &i;
    q = p;
    printf("%p\n", &i);
    printf("%d - %p\n", *p, &p);
    printf("%d - %p\n", *q, &q);

    return 0;
}