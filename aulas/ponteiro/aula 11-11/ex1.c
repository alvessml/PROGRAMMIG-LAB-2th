#include <stdio.h>

int main(){
    int x = 5;
    int *ptr = &x;
    
    printf("%d\n", *ptr); // 5
    printf("%p\n", ptr); //5
     
    return 0;
}