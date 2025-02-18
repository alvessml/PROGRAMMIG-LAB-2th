#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calculo_investimento.c"

// Função para comparar dados financeiros com (ordem: data, tipo, valor)
int comparar_financeiro(const void *a, const void *b) {
    const struct financeiro *fa = (const struct financeiro *)a;
    const struct financeiro *fb = (const struct financeiro *)b;

    int cmp_data = strcmp(fa->dataAplicacao, fb->dataAplicacao);
    if (cmp_data != 0) return cmp_data;

    if (fa->tipo < fb->tipo) return -1;
    if (fa->tipo > fb->tipo) return 1;

    if (fa->valorAplicado < fb->valorAplicado) return -1;
    if (fa->valorAplicado > fb->valorAplicado) return 1;

    return 0;
}

// Função para imprimir o valor bruto total de cada titular
float calcularValorBrutoTotal(struct titular *usr, int index) {
    float totalBruto = 0.0;
    for (int j = 0; j < usr[index].qtd_dados; j++) {
        totalBruto += usr[index].dados[j].valorBruto;
    }
    return totalBruto;
}

// Função para imprimir o valor líquido total de cada titular
float calcularValorLiquidoTotal(struct titular *usr, int index) {
    float totalLiquido = 0.0;
    for (int j = 0; j < usr[index].qtd_dados; j++) {
        totalLiquido += usr[index].dados[j].valorBruto - usr[index].dados[j].valorImposto;
    }
    return totalLiquido;
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
        usr[contTitular].titular[strcspn(usr[contTitular].titular, "\n")] = '\0';

        usr[contTitular].qtd_dados = 0;

        continuar = 'n';
        while (continuar != 's' && usr[contTitular].qtd_dados < MAX_DADOS) {
            adicionarInvestimento(usr, contTitular);

            printf("\nDeseja parar de adicionar dados para este titular? (digite 's' para 'sim'): ");
            scanf(" %c", &continuar);
        }

        contTitular++;

        printf("\nDeseja parar de adicionar titulares? (digite 's' para 'sim'): ");
        scanf(" %c", &finalizar);

        getchar();
    }

    // Atualiza os investimentos e ordena os dados financeiros de cada titular
    for (int i = 0; i < contTitular; i++) {
        for (int j = 0; j < usr[i].qtd_dados; j++) {
            atualizarInvestimento(&usr[i].dados[j]);
        }
        qsort(usr[i].dados, usr[i].qtd_dados, sizeof(struct financeiro), comparar_financeiro);
    }

    // Exibe os dados coletados
    printf("\n\n===== Dados Coletados =====\n");
    for (int i = 0; i < contTitular; i++) {
        printf("\nTitular: %s\n", usr[i].titular);
        printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("%-20s | %-20s | %-20s | %-20s | %-20s | %-20s | %-20s\n", "Data", "Valor Aplicado", "Taxa (%)", "Imposto", "Tipo", "Valor Bruto", "Valor Imposto");
        printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        for (int j = 0; j < usr[i].qtd_dados; j++) {
            printf("%-20s | %-20.2f | %-20.2f | %-20s | %-20d | %-20.2f | %-20.2f\n",
                   usr[i].dados[j].dataAplicacao,
                   usr[i].dados[j].valorAplicado,
                   usr[i].dados[j].taxaJuros * 100,
                   usr[i].dados[j].tipoImposto,
                   usr[i].dados[j].tipo,
                   usr[i].dados[j].valorBruto,
                   usr[i].dados[j].valorImposto);
        }

        float totalBruto = calcularValorBrutoTotal(usr, i);
        printf("\nValor Bruto Total de %s: %.2f\n", usr[i].titular, totalBruto);

        float totalLiquido = calcularValorLiquidoTotal(usr, i);
        printf("Valor Líquido Total de %s: %.2f\n", usr[i].titular, totalLiquido);
    }

    return 0;
}