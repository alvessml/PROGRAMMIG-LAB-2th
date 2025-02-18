#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_TITULARES 100
#define MAX_DADOS 100

// Enum para os tipos de investimento
typedef enum {
    PREFIXADO,
    IPCA_MAIS,
    SELIC,
    CDI
} TipoInvestimento;

// Estrutura para armazenar dados financeiros
struct financeiro {
    char dataAplicacao[11];
    char dataVencimento[11]; // Agora a data de vencimento é individual para cada investimento
    float valorAplicado; // Valor inicial
    float taxaJuros;     // Taxa de juros anual
    char tipoImposto[20]; // Tipo de imposto
    float valorBruto;    // Valor final bruto
    float valorImposto;  // Valor do imposto
    TipoInvestimento tipo; // Tipo de investimento usando a Enum
    char nomeInvestimento[100]; // Nome do investimento
};

// Estrutura para armazenar titulares e seus dados financeiros
struct titular {
    char titular[MAX_TITULARES];
    struct financeiro dados[MAX_DADOS];
    int qtd_dados; // Contador para o número de dados por titular
};

// Função para calcular a diferença de dias entre duas datas
int calcularDiferencaDias(const char *dataInicial, const char *dataFinal) {
    struct tm tm_inicial = {0}, tm_final = {0};

    // Converter strings de data para struct tm
    sscanf(dataInicial, "%d/%d/%d", &tm_inicial.tm_mday, &tm_inicial.tm_mon, &tm_inicial.tm_year);
    sscanf(dataFinal, "%d/%d/%d", &tm_final.tm_mday, &tm_final.tm_mon, &tm_final.tm_year);

    tm_inicial.tm_mon -= 1;  // Ajusta mês (0-11)
    tm_inicial.tm_year -= 1900; // Ajusta ano (anos desde 1900)

    tm_final.tm_mon -= 1;
    tm_final.tm_year -= 1900;

    // Converter para time_t
    time_t t_inicial = mktime(&tm_inicial);
    time_t t_final = mktime(&tm_final);

    // Calcular diferença em dias
    return (int)difftime(t_final, t_inicial) / (60 * 60 * 24);
}

// Função para calcular o imposto baseado no tempo de aplicação
float calcularImposto(int dias) {
    if (dias <= 180) {
        return 0.225; // 22,5% de imposto
    } else if (dias <= 360) {
        return 0.20;  // 20% de imposto
    } else if (dias <= 720) {
        return 0.175; // 17,5% de imposto
    } else {
        return 0.15;  // 15% de imposto
    }
}

// Função para comparar dados financeiros com (ordem: data, tipo, valor)
int comparar_financeiro(const void *a, const void *b) {
    const struct financeiro *fa = (const struct financeiro *)a;
    const struct financeiro *fb = (const struct financeiro *)b;

    // Comparação por data
    int cmp_data = strcmp(fa->dataAplicacao, fb->dataAplicacao);
    if (cmp_data != 0) return cmp_data;

    // Comparação por tipo
    if (fa->tipo < fb->tipo) return -1;
    if (fa->tipo > fb->tipo) return 1;

    // Comparação por valor (crescente)
    if (fa->valorAplicado < fb->valorAplicado) return -1;
    if (fa->valorAplicado > fb->valorAplicado) return 1;

    return 0;
}

// Função para atualizar o investimento com juros compostos
void atualizarInvestimento(struct financeiro *investimento) {
    // Calcular diferença de dias entre dataAplicacao e dataVencimento
    int dias = calcularDiferencaDias(investimento->dataAplicacao, investimento->dataVencimento);

    if (dias < 0) {
        printf("Erro: A data de aplicação é posterior à data de vencimento.\n");
        return;
    }

    // Calcular juros diário com base na taxa anual informada
    double jurosDiario = pow(1 + investimento->taxaJuros, 1.0 / 365) - 1;

    // Calcular valor bruto (juros compostos)
    investimento->valorBruto = investimento->valorAplicado * pow(1 + jurosDiario, dias);

    // Calcular o imposto com base no tempo de aplicação
    float impostoPercentual = calcularImposto(dias);
    investimento->valorImposto = investimento->valorBruto * impostoPercentual;
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
        usr[contTitular].titular[strcspn(usr[contTitular].titular, "\n")] = '\0'; // Remove o '\n'

        usr[contTitular].qtd_dados = 0;

        continuar = 'n';
        while (continuar != 's' && usr[contTitular].qtd_dados < MAX_DADOS) {
            int contDados = usr[contTitular].qtd_dados;

            printf("Insira a data de aplicação (DD/MM/AAAA): ");
            scanf("%10s", usr[contTitular].dados[contDados].dataAplicacao);

            printf("Insira a data de vencimento (DD/MM/AAAA): ");
            scanf("%10s", usr[contTitular].dados[contDados].dataVencimento);

            printf("Insira o valor aplicado (R$): ");
            scanf("%f", &usr[contTitular].dados[contDados].valorAplicado);

            printf("Insira a taxa de juros anual (exemplo: 0.05 para 5%%): ");
            scanf("%f", &usr[contTitular].dados[contDados].taxaJuros);

            getchar(); // Limpa o buffer (não é mais necessário após a correção)
            printf("Insira o tipo de imposto (exemplo: IR): ");
            fgets(usr[contTitular].dados[contDados].tipoImposto, sizeof(usr[contTitular].dados[contDados].tipoImposto), stdin);
            usr[contTitular].dados[contDados].tipoImposto[strcspn(usr[contTitular].dados[contDados].tipoImposto, "\n")] = '\0';

            printf("Insira o tipo do investimento (0-Prefixado, 1-IPCA+, 2-Selic, 3-CDI): ");
            int tipo;
            scanf("%d", &tipo);
            usr[contTitular].dados[contDados].tipo = (TipoInvestimento)tipo;

            getchar(); // Limpa o buffer
            printf("Insira o nome do investimento: ");
            fgets(usr[contTitular].dados[contDados].nomeInvestimento, sizeof(usr[contTitular].dados[contDados].nomeInvestimento), stdin);
            usr[contTitular].dados[contDados].nomeInvestimento[strcspn(usr[contTitular].dados[contDados].nomeInvestimento, "\n")] = '\0';

            usr[contTitular].qtd_dados++;

            printf("\nDeseja parar de adicionar dados para este titular? (digite 's' para 'sim'): ");
            scanf(" %c", &continuar); // Espaço antes do %c para ignorar espaços em branco
        }

        contTitular++;

        printf("\nDeseja parar de adicionar titulares? (digite 's' para 'sim'): ");
        scanf(" %c", &finalizar); // Espaço antes do %c para ignorar espaços em branco

        getchar(); // Limpa o buffer (não é mais necessário após a correção)
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

        // Imprime o valor bruto total do titular
        float totalBruto = calcularValorBrutoTotal(usr, i);
        printf("\nValor Bruto Total de %s: %.2f\n", usr[i].titular, totalBruto);

        // Imprime o valor líquido total do titular
        float totalLiquido = calcularValorLiquidoTotal(usr, i);
        printf("Valor Líquido Total de %s: %.2f\n", usr[i].titular, totalLiquido);
    }

    return 0;
}
