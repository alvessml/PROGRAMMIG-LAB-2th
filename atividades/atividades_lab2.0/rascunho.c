#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_TITULARES 100
#define MAX_DADOS 100
#define TAXA_JUROS_ANUAL 5.0 // 5% ao ano

// Variável global para a data atual
char dataAtual[11];

// Estrutura para armazenar dados financeiros
struct financeiro {
    char dataAplicacao[11];
    float valorAplicado;
    float valorBruto; // Novo campo para armazenar o valor com juros
    char tipo[100];
    char nome[100];
};

// Estrutura para armazenar titulares e seus dados financeiros
struct titular {
    char titular[100];
    struct financeiro dados[MAX_DADOS];
    int qtd_dados; // Contador para o número de dados por titular
};

// Função para calcular a diferença de dias entre duas datas
int calcularDiferencaDias(const char *dataInicial, const char *dataFinal) {
    struct tm tm_inicial = {0}, tm_final = {0};

    // Converter strings de data para struct tm
    if (sscanf(dataInicial, "%d/%d/%d", &tm_inicial.tm_mday, &tm_inicial.tm_mon, &tm_inicial.tm_year) != 3) {
        printf("Erro: Data inicial no formato inválido.\n");
        return -1;
    }
    if (sscanf(dataFinal, "%d/%d/%d", &tm_final.tm_mday, &tm_final.tm_mon, &tm_final.tm_year) != 3) {
        printf("Erro: Data final no formato inválido.\n");
        return -1;
    }

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

// Função para atualizar o investimento com juros compostos
void atualizarInvestimento(struct financeiro *investimento) {
    // Calcular diferença de dias entre dataAplicacao e dataAtual
    int dias = calcularDiferencaDias(investimento->dataAplicacao, dataAtual);

    if (dias < 0) {
        printf("Aviso: A data de aplicação (%s) é posterior à data atual (%s). Ignorando este investimento.\n",
               investimento->dataAplicacao, dataAtual);
        investimento->valorBruto = investimento->valorAplicado; // Sem crescimento
        return;
    }

    // Calcular juros diário com base na taxa anual
    double taxaAnual = TAXA_JUROS_ANUAL / 100.0;
    double jurosDiario = pow(1 + taxaAnual, 1.0 / 365) - 1;

    // Calcular valor bruto (juros compostos)
    investimento->valorBruto = investimento->valorAplicado * pow(1 + jurosDiario, dias);
}

// Função para comparar dados financeiros (ordem: data, tipo, valor)
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
    // Definir a data atual
    printf("Insira a data atual (DD/MM/AAAA): ");
    scanf("%10s", dataAtual);

    struct titular usr[MAX_TITULARES];
    int contTitular = 0;

    printf("===== Preencha os dados a seguir =====\n");

    char continuar = 'n';
    char finalizar = 'n';

    while (finalizar != 's' && contTitular < MAX_TITULARES) {
        printf("\nInsira o nome do titular: ");
        getchar(); // Limpa o buffer
        fgets(usr[contTitular].titular, sizeof(usr[contTitular].titular), stdin);
        usr[contTitular].titular[strcspn(usr[contTitular].titular, "\n")] = '\0'; // Remove o '\n'

        usr[contTitular].qtd_dados = 0;

        continuar = 'n';
        while (continuar != 's' && usr[contTitular].qtd_dados < MAX_DADOS) {
            int contDados = usr[contTitular].qtd_dados;

            printf("Insira a data (DD/MM/AAAA): ");
            scanf("%10s", usr[contTitular].dados[contDados].dataAplicacao);

            printf("Insira o valor (R$): ");
            scanf("%f", &usr[contTitular].dados[contDados].valorAplicado);

            getchar(); // Limpa o buffer
            printf("Insira o tipo: ");
            fgets(usr[contTitular].dados[contDados].tipo, sizeof(usr[contTitular].dados[contDados].tipo), stdin);
            usr[contTitular].dados[contDados].tipo[strcspn(usr[contTitular].dados[contDados].tipo, "\n")] = '\0';

            printf("Insira o nome: ");
            fgets(usr[contTitular].dados[contDados].nome, sizeof(usr[contTitular].dados[contDados].nome), stdin);
            usr[contTitular].dados[contDados].nome[strcspn(usr[contTitular].dados[contDados].nome, "\n")] = '\0';

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

    // Atualiza os investimentos e ordena os dados financeiros de cada titular
    for (int i = 0; i < contTitular; i++) {
        for (int j = 0; j < usr[i].qtd_dados; j++) {
            atualizarInvestimento(&usr[i].dados[j]);
        }
        qsort(usr[i].dados, usr[i].qtd_dados, sizeof(struct financeiro), comparar_financeiro);
    }

    // Exibe os dados coletados
    printf("\n\n===== Dados Coletados (Ordenados) =====\n");
    for (int i = 0; i < contTitular; i++) {
        printf("\nTitular: %s\n", usr[i].titular);
        printf("---------------------------------------------------------------\n");
        printf("%-15s | %-15s | %-15s | %-20s | %-15s\n", "Data", "Valor Aplicado", "Valor Bruto", "Tipo", "Nome");
        printf("---------------------------------------------------------------\n");

        for (int j = 0; j < usr[i].qtd_dados; j++) {
            printf("%-15s | %-15.2f | %-15.2f | %-20s | %-15s\n",
                   usr[i].dados[j].dataAplicacao,
                   usr[i].dados[j].valorAplicado,
                   usr[i].dados[j].valorBruto,
                   usr[i].dados[j].tipo,
                   usr[i].dados[j].nome);
        }
    }

    return 0;
}