#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h> // Para acentuação e Sleep
#include <unistd.h>  // Para sleep e usleep
#include <locale.h>  // Para setlocale

// --- ESTRUTURAS DE DADOS ---

typedef struct {
    char nome[50]; // Espaço para nome e emoji
    int multiplicador;
} Simbolo;

typedef struct {
    int rodadas_jogadas;
    int vitorias;
    int derrotas;
    double ganhos_totais;
    double perdas_totais;
} Relatorio;


// --- PROTÓTIPOS DAS FUNÇÕES ---
void configurarConsole();
void limparTela();
void pausar(int milissegundos);
void limparBufferEntrada();
void exibirMenu(double creditos);
void jogar(double* creditos, Simbolo simbolos[], int num_simbolos, Relatorio* rel);
void exibirRegras();
void exibirRelatorio(Relatorio rel, double creditos_iniciais);
void depositar(double* creditos);
void sacar(double* creditos);


// --- FUNÇÃO PRINCIPAL ---
int main() {
    configurarConsole();
    srand(time(NULL));

    Simbolo simbolos[] = {
        {"🍒 Cereja  ", 2},
        {"🍋 Limão   ", 3},
        {"🍊 Laranja ", 5},
        {"🎰 Bar     ", 10},
        {"7️⃣  Sete    ", 25},
        {"💎 DIAMANTE", 50},
        {"🦈 SAHUR   ", 100}
    };
    int num_simbolos = sizeof(simbolos) / sizeof(simbolos[0]);
    
    double creditos_iniciais = 0.0;
    double creditos = creditos_iniciais;
    Relatorio rel = {0, 0, 0, 0.0, 0.0};
    int escolha = 0;

    do {
        limparTela();
        exibirMenu(creditos);
        
        if (scanf("%d", &escolha) != 1) {
            printf("Opção inválida. Pressione Enter para tentar novamente.\n");
            limparBufferEntrada();
            getchar();
            continue;
        }
        limparBufferEntrada();

        switch (escolha) {
            case 1: jogar(&creditos, simbolos, num_simbolos, &rel); break;
            case 2: exibirRegras(); break;
            case 3: exibirRelatorio(rel, creditos_iniciais); break;
            case 4: depositar(&creditos); break;
            case 5: sacar(&creditos); break;
            case 0: 
                printf("Obrigado por jogar Fortune Sahur!\n");
                break;
            default:
                printf("Opção inválida. Pressione Enter para continuar.\n");
                getchar();
        }

    } while (escolha != 0);

    return 0;
}


// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

void configurarConsole() {
#ifdef _WIN32
    // Garante que o console do Windows possa exibir emojis (UTF-8)
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#else
    // Método para Linux/macOS
    setlocale(LC_ALL, "Portuguese");
#endif
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar(int milissegundos) {
#ifdef _WIN32
    Sleep(milissegundos);
#else
    usleep(milissegundos * 1000);
#endif
}

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu(double creditos) {
    printf("########################################\n");
    printf("#            FORTUNE SAHUR             #\n");
    printf("########################################\n\n");
    printf("Seus Créditos: R$ %.2f\n\n", creditos);
    printf("Escolha uma opção:\n");
    printf("1 - Jogar\n");
    printf("2 - Regras do Jogo\n");
    printf("3 - Relatório de Ganhos e Perdas\n");
    printf("4 - Depositar Créditos\n");
    printf("5 - Sacar Créditos\n");
    printf("0 - Sair do Jogo\n\n");
    printf("Sua escolha: ");
}

void jogar(double* creditos, Simbolo simbolos[], int num_simbolos, Relatorio* rel) {
    limparTela();
    if (*creditos <= 0) {
        printf("Você não tem créditos suficientes para jogar.\n");
        printf("Vá para o menu de depósito para adicionar mais.\n\n");
        printf("Pressione Enter para voltar ao menu.\n");
        getchar();
        return;
    }

    double aposta_atual = 0;
    while (1) {
        printf("Seus créditos: R$ %.2f\n", *creditos);
        printf("Defina sua aposta inicial (0 para voltar): ");
        if (scanf("%lf", &aposta_atual) != 1) {
            printf("Entrada inválida.\n");
            limparBufferEntrada();
            continue;
        }
        limparBufferEntrada();

        if (aposta_atual == 0) return;
        if (aposta_atual > *creditos) { printf("Aposta maior que seus créditos.\n"); }
        else if (aposta_atual <= 0) { printf("A aposta deve ser um valor positivo.\n"); }
        else break;
    }

    int comando;
    while (1) {
        limparTela();
        if (aposta_atual > *creditos) {
            printf("Créditos insuficientes para a aposta de R$ %.2f!\n", aposta_atual);
            printf("Saia para depositar mais créditos.\n");
            pausar(2500);
        } else {
            *creditos -= aposta_atual;
            rel->rodadas_jogadas++;
            rel->perdas_totais += aposta_atual;

            Simbolo grade[3][3];
            for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) grade[i][j] = simbolos[rand() % num_simbolos];

            for (int k = 0; k < 15; k++) {
                limparTela();
                printf("Girando com aposta de R$ %.2f...\n\n", aposta_atual);
                for(int i = 0; i < 3; i++) {
                    Simbolo s1 = simbolos[rand() % num_simbolos];
                    Simbolo s2 = simbolos[rand() % num_simbolos];
                    Simbolo s3 = simbolos[rand() % num_simbolos];
                    printf(" | %-20s | %-20s | %-20s |\n", s1.nome, s2.nome, s3.nome);
                }
                pausar(60);
            }
            
            limparTela();
            printf("Créditos: R$ %.2f   |   Aposta: R$ %.2f\n", *creditos, aposta_atual);
            printf("--------------------------------------------------------\n");
            printf("Resultado Final:\n\n");
            for(int i = 0; i < 3; i++) {
                printf(" | %-20s | %-20s | %-20s |\n", grade[i][0].nome, grade[i][1].nome, grade[i][2].nome);
            }
            pausar(1000);

            double premio_rodada = 0;
            int linhas_vencedoras = 0;
            
            for(int i = 0; i < 3; i++) if (strcmp(grade[i][0].nome, grade[i][1].nome) == 0 && strcmp(grade[i][1].nome, grade[i][2].nome) == 0) {
                premio_rodada += aposta_atual * grade[i][0].multiplicador;
                linhas_vencedoras++;
            }
            if (strcmp(grade[0][0].nome, grade[1][1].nome) == 0 && strcmp(grade[1][1].nome, grade[2][2].nome) == 0) {
                premio_rodada += aposta_atual * grade[0][0].multiplicador;
                linhas_vencedoras++;
            }
            if (strcmp(grade[0][2].nome, grade[1][1].nome) == 0 && strcmp(grade[1][1].nome, grade[2][0].nome) == 0) {
                premio_rodada += aposta_atual * grade[0][2].multiplicador;
                linhas_vencedoras++;
            }

            printf("\n--------------------------------------------------------\n");
            if (premio_rodada > 0) {
                printf("PARABÉNS! Você acertou %d linha(s)!\n", linhas_vencedoras);
                *creditos += premio_rodada;
                rel->ganhos_totais += premio_rodada;
                rel->vitorias++;
            } else {
                printf("Não foi dessa vez. Sem prêmios.\n");
                rel->derrotas++;
            }
            printf("Seus créditos agora: R$ %.2f / Vitória de: R$ %.2f\n", *creditos, premio_rodada);
            printf("--------------------------------------------------------\n\n");
        }

        printf("Pressione [Enter] para girar novamente | 'v' para Voltar ao menu: ");
        comando = getchar();

        if (comando == 'v' || comando == 'V') {
            if (comando != '\n') limparBufferEntrada();
            break;
        }
        else if (comando != '\n') {
            limparBufferEntrada();
        }
    }
}

void exibirRegras() {
    limparTela();
    printf("============== REGRAS DO FORTUNE SAHUR ==============\n\n");
    printf("1. O objetivo é combinar 3 símbolos iguais em uma das 5 linhas de pagamento.\n\n");
    printf("2. As linhas de pagamento são:\n");
    printf("   - As 3 linhas horizontais.\n");
    printf("   - As 2 linhas diagonais.\n\n");
    printf("3. O prêmio para cada linha vencedora é o [VALOR DA APOSTA] x [MULTIPLICADOR DO SÍMBOLO].\n\n");
    printf("4. É possível ganhar em múltiplas linhas na mesma rodada. Os prêmios são somados.\n\n");
    printf("5. Multiplicadores:\n");
    printf("   🍒 Cereja  : 2x\n");
    printf("   🍋 Limão   : 3x\n");
    printf("   🍊 Laranja : 5x\n");
    printf("   🎰 Bar     : 10x\n");
    printf("   7️⃣  Sete   : 25x\n");
    printf("   💎 DIAMANTE: 50x\n");
    printf("   🦈 SAHUR   : 100x\n");
    printf("\n=======================================================\n");
    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}

void exibirRelatorio(Relatorio rel, double creditos_iniciais) {
    limparTela();
    double balanco = rel.ganhos_totais - rel.perdas_totais;
    float taxa_vitoria = (rel.rodadas_jogadas > 0) ? ((float)rel.vitorias / rel.rodadas_jogadas) * 100.0f : 0.0f;

    printf("================= RELATÓRIO DE SESSÃO =================\n\n");
    printf("Créditos Iniciais: R$ %.2f\n\n", creditos_iniciais);
    printf("Rodadas Jogadas: %d\n", rel.rodadas_jogadas);
    printf("Vitórias: %d\n", rel.vitorias);
    printf("Derrotas: %d\n", rel.derrotas);
    printf("Taxa de Vitória: %.2f%%\n\n", taxa_vitoria);
    printf("Total Ganho (soma de prêmios): R$ %.2f\n", rel.ganhos_totais);
    printf("Total Apostado: R$ %.2f\n", rel.perdas_totais);
    printf("\n-------------------------------------------------------\n");
    printf("Balanço Final (Ganhos - Perdas): R$ %.2f\n", balanco);
    printf("=======================================================\n");
    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}

void depositar(double* creditos) {
    limparTela();
    double valor_deposito;
    printf("========= DEPÓSITO DE CRÉDITOS =========\n\n");
    printf("Saldo atual: R$ %.2f\n", *creditos);
    printf("Digite o valor que deseja depositar (0 para cancelar): ");
    
    if (scanf("%lf", &valor_deposito) != 1) {
        printf("Valor inválido.\n");
        limparBufferEntrada();
    } else {
        limparBufferEntrada();
        if (valor_deposito < 0) {
            printf("Não é possível depositar um valor negativo.\n");
        } else if (valor_deposito > 0) {
            *creditos += valor_deposito;
            printf("\nDepósito de R$ %.2f realizado com sucesso!\n", valor_deposito);
            printf("Novo saldo: R$ %.2f\n", *creditos);
        }
    }
    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}

void sacar(double* creditos) {
    limparTela();
    double valor_saque;
    printf("========= SAQUE DE CRÉDITOS =========\n\n");
    printf("Saldo disponível para saque: R$ %.2f\n", *creditos);
    printf("Digite o valor que deseja sacar (0 para cancelar): ");

    if (scanf("%lf", &valor_saque) != 1) {
        printf("Valor inválido.\n");
        limparBufferEntrada();
    } else {
        limparBufferEntrada();
        if (valor_saque < 0) {
            printf("Não é possível sacar um valor negativo.\n");
        } else if (valor_saque > *creditos) {
            printf("Valor de saque maior que o saldo disponível.\n");
        } else if (valor_saque > 0) {
            *creditos -= valor_saque;
            printf("\nSaque de R$ %.2f realizado com sucesso!\n", valor_saque);
            printf("Saldo restante: R$ %.2f\n", *creditos);
        }
    }
    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}
