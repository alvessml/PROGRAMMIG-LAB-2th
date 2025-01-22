#include <stdio.h>
#include <string.h>

void imprimir_centralizado(const char *, int);

#define TAM 100

struct financeiro {
        char titular[TAM];
        char data[11];
        float valor;
        char tipo[TAM];
        char nome[TAM];
    };

int main(){
    struct financeiro dados[TAM];
    int cont = 0;
    char continuar = 'n';
    printf("_____Preenche os dados a seguir_____\n");
    while(continuar != 's' && cont < TAM){
        printf("Insira o titular: ");
        fgets(dados[cont].titular, sizeof(dados[cont].titular), stdin);
        dados[cont].titular[strcspn(dados[cont].titular, "\n")] = '\0'; // Remove o '\n' e substitui por caractere nulo '\0'

        printf("Insira data (DD/MM/AAAA): ");
        scanf("%s", dados[cont].data);

        printf("Insira valor: R$");
        scanf("%f", &dados[cont].valor);
        
        getchar();
        printf("Insira tipo: ");
        fgets(dados[cont].tipo, sizeof(dados[cont].tipo), stdin);
        dados[cont].tipo[strcspn(dados[cont].tipo, "\n")] = '\0'; // Remove o '\n' e substitui por caractere nulo '\0'

        printf("Insira nome: ");
        fgets(dados[cont].nome, sizeof(dados[cont].nome), stdin);
        dados[cont].nome[strcspn(dados[cont].nome, "\n")] = '\0'; // Remove o '\n' e substitui por caractere nulo '\0'

        cont += 1;

        printf("Deseja parar a execução? (digite 's' para 'sair'): ");
        scanf("%c", &continuar);
        getchar();
    }

    printf("\n---------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-20s | %-10s |", "Data", "Valor", "Tipo", "Nome");
    printf("\n---------------------------------------------------------------\n");

    for(int k=0; k < cont; k++){
        imprimir_centralizado(dados[k].titular, 66);
        printf("\n| %-10s | R$%-10.2f | %-20s | %-10s |\n", dados[k].data, dados[k].valor, dados[k].tipo, dados[k].nome);
    }

    return 0;
}


void imprimir_centralizado(const char *str, int largura_total) {
    int comprimento_str = strlen(str);
    int espacos_esquerda = (largura_total - comprimento_str) / 2;
    int espacos_direita = largura_total - comprimento_str - espacos_esquerda;

    printf("%*s%s%*s\n", espacos_esquerda, "", str, espacos_direita, "");
}