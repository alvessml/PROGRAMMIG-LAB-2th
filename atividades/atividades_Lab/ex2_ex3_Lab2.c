#include <stdio.h>
#include <ctype.h>

void inserirNormal();
void inserirPrioridade();
void consumirSenha();
void visualizarSenha();
void limparBuffer();
void ordenarSenhas();

#define TAM 100

typedef struct {
    int numero;
    char estado; // 'N' para NORMAL, 'P' para PRIORIDADE
} Senha;

Senha senhas[TAM];
int totalSenhas = 0;  // Variável para controlar o total de senhas inseridas
int ultimaConsumida = 0;  // Controla a alternância entre NORMAL e PRIORIDADE

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
    if(totalSenhas < TAM){
        Senha novaSenha;
        novaSenha.numero = totalSenhas + 1;
        novaSenha.estado = 'N';
        senhas[totalSenhas] = novaSenha;
        totalSenhas++;
        ordenarSenhas();
        printf("Senha (NORMAL) inserida. Número: %d\n\n", novaSenha.numero);
    } else{
        printf("Limire de senhas atingido. \n\n");
    }
}

void inserirPrioridade(){
    if (totalSenhas < TAM) {
        Senha novaSenha;
        novaSenha.numero = totalSenhas + 1;
        novaSenha.estado = 'P';
        senhas[totalSenhas] = novaSenha;
        totalSenhas++;
        ordenarSenhas();
        printf("Senha (PRIORIDADE) inserida. Número: %d\n\n", novaSenha.numero);
    } else {
        printf("Limite de senhas atingido.\n\n");
    }
}

void consumirSenha(){
    if (totalSenhas > 0) {
        int i;
        Senha senhaConsumida;

        // Buscar a próxima senha a ser consumida de forma alternada
        if (ultimaConsumida % 2 == 0) {
            // Procurar a primeira PRIORIDADE não consumida
            for (i = 0; i < totalSenhas; i++) {
                if (senhas[i].estado == 'P') {
                    senhaConsumida = senhas[i];
                    // Remove a senha consumida
                    for (int j = i; j < totalSenhas - 1; j++) {
                        senhas[j] = senhas[j + 1];
                    }
                    totalSenhas--;
                    ultimaConsumida++;
                    printf("Consumindo senha de PRIORIDADE. Número: %d\n\n", senhaConsumida.numero);
                    return;
                }
            }
        }

        // Procurar a próxima senha de NORMAL
        for (i = 0; i < totalSenhas; i++) {
            if (senhas[i].estado == 'N') {
                senhaConsumida = senhas[i];
                // Remove a senha consumida
                for (int j = i; j < totalSenhas - 1; j++) {
                    senhas[j] = senhas[j + 1];
                }
                totalSenhas--;
                ultimaConsumida++;
                printf("Consumindo senha NORMAL. Número: %d\n\n", senhaConsumida.numero);
                return;
            }
        }

        // Se não encontrou senha de PRIORIDADE ou NORMAL
        printf("Não há senhas disponíveis para consumir.\n\n");
    } else {
        printf("Não há senhas para consumir.\n\n");
    }
}

void visualizarSenha(){
    if (totalSenhas > 0) {
        printf("Senhas não consumidas:\n");
        for (int i = 0; i < totalSenhas; i++) {
            printf("Número: %d, Estado: %c\n", senhas[i].numero, senhas[i].estado);
        }
    } else {
        printf("Não há senhas para visualizar.\n\n");
    }
}

void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void ordenarSenhas(){
    // Ordena as senhas com as de PRIORIDADE antes das de NORMAL
    for (int i = 0; i < totalSenhas - 1; i++) {
        for (int j = i + 1; j < totalSenhas; j++) {
            if (senhas[i].estado == 'N' && senhas[j].estado == 'P') {
                // Troca as senhas
                Senha temp = senhas[i];
                senhas[i] = senhas[j];
                senhas[j] = temp;
            }
        }
    }
}