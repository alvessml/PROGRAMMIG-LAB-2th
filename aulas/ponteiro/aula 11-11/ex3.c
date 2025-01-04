#include <stdio.h>

int main(){
    int x = 5;
    int y = 10;

    int *px, *py;

    px = &x;
    py = &y;

    *px = *py;
 
    return 0;
}