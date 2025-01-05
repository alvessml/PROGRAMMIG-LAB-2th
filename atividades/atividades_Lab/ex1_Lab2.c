#include <stdio.h>
#include <ctype.h>

void inserirNormal();
void inserirPrioridade();
void consumirSenha();
void visualizarSenha();
void limparBuffer();

int main(){
    char entrada_usr_inicial, entrada_usr_modificado;

    while(1){
        printf("N - InserirNormal \nP - InserirPrioridade \nC - ConsumirSenha \nS - Sair do prgrama \nV - Visualiza todas as senhas não consumidas \nDigite alguma letra: ");
        scanf("%c", & entrada_usr_inicial);

        entrada_usr_modificado = tolower(entrada_usr_inicial);    

        limparBuffer();

        switch(entrada_usr_modificado){
            case('n'):
                inserirNormal();
                break;
            case('p'):
                inserirPrioridade();
                break;
            case('c'):
                consumirSenha();
                break;
            case('s'):
                printf("Finalizando o programa!\n");
                return 0;
            case('v'):
                visualizarSenha();
                break;
            default:
                printf("Erro! Digite somente uma letra.");
        }
    }
    return 0;
}

void inserirNormal(){
    printf("Inserindo normal...\n\n");
}

void inserirPrioridade(){
    printf("Inserindo prioridade...\n\n");
}

void consumirSenha(){
    printf("Inserindo consumir senha...\n\n");
}

void visualizarSenha(){
    printf("Visualizando senha...\n\n");
}

void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}