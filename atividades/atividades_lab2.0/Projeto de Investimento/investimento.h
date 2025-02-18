#ifndef INVESTIMENTOS_H
#define INVESTIMENTOS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    char dataVencimento[11];
    float valorAplicado;
    float taxaJuros;
    char tipoImposto[20];
    float valorBruto;
    float valorImposto;
    TipoInvestimento tipo;
    char nomeInvestimento[100];
};

// Estrutura para armazenar titulares e seus dados financeiros
struct titular {
    char titular[MAX_TITULARES];
    struct financeiro dados[MAX_DADOS];
    int qtd_dados;
};

// Função para adicionar um novo investimento
void adicionarInvestimento(struct titular *usr, int index);

// Função para excluir um investimento
void excluirInvestimento(struct titular *usr, int index, int investimentoIndex);

#endif // INVESTIMENTOS_H
