#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TITULARES 100
#define MAX_DADOS 100

// Estrutura para armazenar dados financeiros
struct financeiro {
    char dataAplicacao[11];
    float valorAplicado;
    char tipo[100];
    char nome[100];
    char dataVencimento[11];
    float taxaJuros;
    char imposto[3];
    float valor;
};

// Estrutura para armazenar titulares e seus dados financeiros
struct titular {
    char titular[100];
    struct financeiro dados[MAX_DADOS];
    int qtd_dados; // Contador para o número de dados por titular
};



// Função para comparar dados financeiros com (ordem: data, tipo, valor)
int comparar_financeiro(const void *a, const void *b) {
    const struct financeiro *fa = (const struct financeiro *)a;
    const struct financeiro *fb = (const struct financeiro *)b;

    // Comparação por data
    int cmp_data = strcmp(fa->dataAplicacao, fb->dataAplicacao);
    if (cmp_data != 0) return cmp_data;

    // Comparação por tipo
    int cmp_tipo = strcmp(fa->tipo, fb->tipo);
    if (cmp_tipo != 0) return cmp_tipo;

    // Comparação por valor (crescente)
    if (fa->valorAplicado < fb->valorAplicado) return -1;
    if (fa->valorAplicado > fb->valorAplicado) return 1;

    return 0;
}



int main() {
    struct titular usr[MAX_TITULARES];
    int contTitular = 0;

    printf("===== Preencha os dados a seguir =====\n");

    char continuar = 'n';
    char finalizar = 'n';

    while (finalizar != 's' && contTitular < MAX_TITULARES) {
        printf("\nInsira o nome do titular: ");
        fgets(usr[contTitular].titular, sizeof(usr[contTitular].titular), stdin);
        usr[contTitular].titular[strcspn(usr[contTitular].titular, "\n")] = '\0'; // Remove o '\n'

        usr[contTitular].qtd_dados = 0;

        continuar = 'n';
        while (continuar != 's' && usr[contTitular].qtd_dados < MAX_DADOS) {
            int contDados = usr[contTitular].qtd_dados;

            printf("Insira a data de aplicação (DD/MM/AAAA): ");
            scanf("%10s", usr[contTitular].dados[contDados].dataAplicacao);

            printf("Insira o valor da aplicação (R$): ");
            scanf("%f", &usr[contTitular].dados[contDados].valorAplicado);

            getchar(); // Limpa o buffer
            printf("Insira o tipo: ");
            fgets(usr[contTitular].dados[contDados].tipo, sizeof(usr[contTitular].dados[contDados].tipo), stdin);
            usr[contTitular].dados[contDados].tipo[strcspn(usr[contTitular].dados[contDados].tipo, "\n")] = '\0';

            printf("Insira o nome: ");
            fgets(usr[contTitular].dados[contDados].nome, sizeof(usr[contTitular].dados[contDados].nome), stdin);
            usr[contTitular].dados[contDados].nome[strcspn(usr[contTitular].dados[contDados].nome, "\n")] = '\0';

            printf("Insira a data de vecimento (DD/MM/AAAA): ");
            scanf("%10s", usr[contTitular].dados[contDados].dataVencimento);

            printf("Inserir taxa de juros: ");
            scanf("%f", &usr[contTitular].dados[contDados].taxaJuros);

            printf("Inserir imposto: ");
            scanf("%s", usr[contTitular].dados[contDados].imposto);

            usr[contTitular].qtd_dados++;

            printf("\nDeseja parar de adicionar dados para este titular? (digite 's' para 'sim'): ");
            scanf(" %c", &continuar);
            getchar(); // Limpa o buffer
        }

        contTitular++;

        printf("\nDeseja parar de adicionar titulares? (digite 's' para 'sim'): ");
        scanf(" %c", &finalizar);
        getchar(); // Limpa o buffer
    }

    // Ordena os dados financeiros de cada titular
    for (int i = 0; i < contTitular; i++) {
        qsort(usr[i].dados, usr[i].qtd_dados, sizeof(struct financeiro), comparar_financeiro);
    }

    // Exibe os dados coletados
    printf("\n\n===== Dados Coletados (Ordenados) =====\n");
    for (int i = 0; i < contTitular; i++) {
        printf("\nTitular: %s\n", usr[i].titular);
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("%-15s | %-15s | %-20s | %-20s | %-15s | %-10s | %-10s |\n", "Data", "Valor (R$)", "Tipo", "Nome", "Data vencimento", "Taxa Juros", "Imposto");
        printf("---------------------------------------------------------------------------------------------------------\n");

        for (int j = 0; j < usr[i].qtd_dados; j++) {
            printf("%-15s | %-15.2f | %-20s | %-20s | %-15s | %-10.2f | %-10s |\n",
                   usr[i].dados[j].dataAplicacao,
                   usr[i].dados[j].valorAplicado,
                   usr[i].dados[j].tipo,
                   usr[i].dados[j].nome,
                   usr[i].dados[j].dataVencimento,
                   usr[i].dados[j].taxaJuros,
                   usr[i].dados[j].imposto
                   );
        }
    }

    return 0;
}
