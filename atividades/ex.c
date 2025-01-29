#include <stdio.h>
#include <string.h>


#define MAX_TITULARES 100
#define MAX_DADOS 100

struct data {
    char dia;
    char mes;
    char ano;
}

// Estrutura para armazenar dados financeiros
struct financeiro {
    struct data dataAplicacao;
    struct data dataVencimento;
    float valorAplicado;
    char tipo[100];
    char nome[100];
};

// Estrutura para armazenar titulares e seus dados financeiros
struct titular {
    char titular[100];
    struct financeiro dados[MAX_DADOS];
    int qtd_dados; // Contador para o número de dados por titular
};

int main(){
    struct titular usr[MAX_TITULARES];
    int contTitular = 0;

    printf("===== Preencha os dados a seguir =====\n");

    char continuar = 'n';
    char finalizar = 'n';

    while (finalizar != 's' && contTitular < MAX_TITULARES) {
        printf("\nInsira o nome do Titular: ");
        fgets(usr[contTitular].titular, sizeof(usr[contTitular].titular), stdin);
        usr[contTitular].titular[strcspn(usr[contTitular].titular, "\n")] = '\0'; // Remove o \n
        
    }

    return 0;
}