#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "investimento.h"

// Função para calcular a diferença de dias entre duas datas
int calcularDiferencaDias(const char *dataInicial, const char *dataFinal) {
    struct tm tm_inicial = {0}, tm_final = {0};

    sscanf(dataInicial, "%d/%d/%d", &tm_inicial.tm_mday, &tm_inicial.tm_mon, &tm_inicial.tm_year);
    sscanf(dataFinal, "%d/%d/%d", &tm_final.tm_mday, &tm_final.tm_mon, &tm_final.tm_year);

    tm_inicial.tm_mon -= 1;
    tm_inicial.tm_year -= 1900;

    tm_final.tm_mon -= 1;
    tm_final.tm_year -= 1900;

    time_t t_inicial = mktime(&tm_inicial);
    time_t t_final = mktime(&tm_final);

    return (int)difftime(t_final, t_inicial) / (60 * 60 * 24);
}

// Função para calcular o imposto baseado no tempo de aplicação
float calcularImposto(int dias) {
    if (dias <= 180) {
        return 0.225;
    } else if (dias <= 360) {
        return 0.20;
    } else if (dias <= 720) {
        return 0.175;
    } else {
        return 0.15;
    }
}

// Função para atualizar o investimento com juros compostos
void atualizarInvestimento(struct financeiro *investimento) {
    int dias = calcularDiferencaDias(investimento->dataAplicacao, investimento->dataVencimento);

    if (dias < 0) {
        printf("Erro: A data de aplicação é posterior à data de vencimento.\n");
        return;
    }

    double jurosDiario = pow(1 + investimento->taxaJuros, 1.0 / 365) - 1;
    investimento->valorBruto = investimento->valorAplicado * pow(1 + jurosDiario, dias);

    float impostoPercentual = calcularImposto(dias);
    investimento->valorImposto = investimento->valorBruto * impostoPercentual;
}