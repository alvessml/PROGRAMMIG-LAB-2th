#include <stdio.h>
#include <string.h>

#define TAM 100

struct financeiro {
        char data[10];
        float valor;
        char tipo[TAM];
        char nome[TAM];
    };

int main(){
    struct financeiro dados[TAM];
    int cont = 0;
    char continuar = 'n';
    printf("Preenche os dados a seguir");
    while(continuar != 's' && cont < TAM){
        printf("Data no formato(DD/MM/AAAA): ");
        scanf("%s", dados[cont].data);
        printf("Valor: ");
        scanf("%f", &dados[cont].valor);
        printf("Tipo: ");
        fgets(dados[cont].tipo, sizeof(dados[cont].tipo), stdin);
        getchar();
        printf("Nome: ");
        fgets(dados[cont].nome, sizeof(dados[cont].nome), stdin);
        cont += 1;

        printf("Deseja parar a execução? (digite 's' para 'sair'): ");
        scanf("%c", &continuar);
        getchar();
    }

    printf("-----------------------------------------\n");
    printf("| %-10s | %-10s | %-20s | %-10s |\n", "Data", "Valor", "Tipo", "Nome");
    for(int k=0; k < cont; k++){
        printf("| %-10s | %-10f | %-20s | %-10s |\n", dados[k].data, dados[k].valor, dados[k].tipo, dados[k].nome);
    }

    return 0;
}