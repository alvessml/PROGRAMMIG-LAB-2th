#include <stdio.h>

void funcParaMudarLetraRparaL(char);

int main(){
    char var_string[100];
    char *ptr_var_string;
    ptr_var_string = var_string;

    printf("Digite algumas letras: ");
    scanf("%s", var_string);

    funcParaMudarDeRparaL(var_string);

    printf("String modificado: ");

    return 0;
}

void funcParaMudarLetraRparaL(char str){
    char str = "";
    for(int k = 0; k < len(str); k++){
        if(str[k] == 'R'){
            str = 'R'
            str[k] = L;
        }
    }
}


// RLRR