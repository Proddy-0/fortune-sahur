#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <locale.h>
#endif

typedef struct {
    char nome[50];
    int multiplicador;
} Simbolo;

typedef struct {
    int rodadas_jogadas;
    int vitorias;
    int derrotas;
    double ganhos_totais;
    double perdas_totais;
} Relatorio;

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

void exibirSimboloAscii(const char* nome, char out[6][32]) {
    const char* cor_inicio;
    const char* cor_fim = "\033[0m";

    if (strstr(nome, "Cereja")) {
        cor_inicio = "\033[31m";
        strcpy(out[0], "  __    ");
        strcpy(out[1], " /  \\   ");
        strcpy(out[2], "| () |  ");
        strcpy(out[3], "| () |  ");
        strcpy(out[4], " \\__/   ");
        strcpy(out[5], "  ||    ");
    } 
    else if (strstr(nome, "Sete")) {
        cor_inicio = "\033[34m";
        strcpy(out[0], "777777 ");
        strcpy(out[1], "    77 ");
        strcpy(out[2], "   77  ");
        strcpy(out[3], "  77   ");
        strcpy(out[4], " 77    ");
        strcpy(out[5], " 77    ");
    } 
    else if (strstr(nome, "DIAMANTE")) {
        cor_inicio = "\033[36m";
        strcpy(out[0], "  /\\    ");
        strcpy(out[1], " /  \\   ");
        strcpy(out[2], "/ /\\ \\  ");
        strcpy(out[3], "\\ \\/ /  ");
        strcpy(out[4], " \\  /   ");
        strcpy(out[5], "  \\/    ");
    } 
    else if (strstr(nome, "Laranja")) {
        cor_inicio = "\033[33m";
        strcpy(out[0], "  __    ");
        strcpy(out[1], " /  \\   ");
        strcpy(out[2], "|    |  ");
        strcpy(out[3], "|    |  ");
        strcpy(out[4], " \\__/   ");
        strcpy(out[5], "        ");
    } 
    else if (strstr(nome, "Limao")) {
        cor_inicio = "\033[93m";
        strcpy(out[0], "  __   ");
        strcpy(out[1], " /  \\  ");
        strcpy(out[2], "| () | ");
        strcpy(out[3], "| () | ");
        strcpy(out[4], " \\__/  ");
        strcpy(out[5], "       ");
    } 
    else if (strstr(nome, "Bar")) {
        cor_inicio = "\033[97m";
        strcpy(out[0], "______ ");
        strcpy(out[1], "|BAR | ");
        strcpy(out[2], "|    | ");
        strcpy(out[3], "|BAR | ");
        strcpy(out[4], "|    | ");
        strcpy(out[5], "|____| ");
    } 
    else if (strstr(nome, "SAHUR")) {
        cor_inicio = "\033[32m";
        strcpy(out[0], "  _____   ");
		strcpy(out[1], " |(O)(O)  ");
		strcpy(out[2], " |  |  |  ");
		strcpy(out[3], " |  |__|  ");
		strcpy(out[4], " |(---|   ");
		strcpy(out[5], " |____|   ");

    } 
    else {
        cor_inicio = "\033[35m";
        strcpy(out[0], "?????? ");
        strcpy(out[1], "?????? ");
        strcpy(out[2], "?????? ");
        strcpy(out[3], "?????? ");
        strcpy(out[4], "?????? ");
        strcpy(out[5], "?????? ");
    }

    for (int i = 0; i < 6; i++) {
        char temp[32];
        sprintf(temp, "%s%s%s", cor_inicio, out[i], cor_fim);
        strcpy(out[i], temp);
    }
}

int main() {
    configurarConsole();
    srand(time(NULL));

    Simbolo simbolos[] = {
        {"Cereja  ", 2},
        {"Limao   ", 3},
        {"Laranja ", 5},
        {"Bar     ", 10},
        {"Sete    ", 25},
        {"DIAMANTE", 50},
        {"SAHUR   ", 100}
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
            printf("Opcao invalida. Pressione Enter para tentar novamente.\n");
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
                printf("Opcao invalida. Pressione Enter para continuar.\n");
                getchar();
        }

    } while (escolha != 0);

    return 0;
}

void configurarConsole() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#else
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
    printf("Seus Creditos: R$ %.2f\n\n", creditos);
    printf("Escolha uma opcao:\n");
    printf("1 - Jogar\n");
    printf("2 - Regras do Jogo\n");
    printf("3 - Relatorio de Ganhos e Perdas\n");
    printf("4 - Depositar Creditos\n");
    printf("5 - Sacar Creditos\n");
    printf("0 - Sair do Jogo\n\n");
    printf("Sua escolha: ");
}

void jogar(double* creditos, Simbolo simbolos[], int num_simbolos, Relatorio* rel) {
    limparTela();
    if (*creditos <= 0) {
        printf("Voce nao tem creditos suficientes para jogar.\n");
        printf("Vá para o menu de deposito para adicionar mais.\n\n");
        printf("Pressione Enter para voltar ao menu.\n");
        getchar();
        return;
    }

    double aposta_atual = 0;
    while (1) {
        printf("Seus creditos: R$ %.2f\n", *creditos);
        printf("Defina sua aposta inicial (0 para voltar): ");
        if (scanf("%lf", &aposta_atual) != 1) {
            printf("Entrada invalida.\n");
            limparBufferEntrada();
            continue;
        }
        limparBufferEntrada();

        if (aposta_atual == 0) return;
        if (aposta_atual > *creditos) { printf("Aposta maior que seus creditos.\n"); }
        else if (aposta_atual <= 0) { printf("A aposta deve ser um valor positivo.\n"); }
        else break;
    }

    int comando;
    while (1) {
        limparTela();
        if (aposta_atual > *creditos) {
            printf("Creditos insuficientes para a aposta de R$ %.2f!\n", aposta_atual);
            pausar(2500);
        } else {
            *creditos -= aposta_atual;
            rel->rodadas_jogadas++;
            rel->perdas_totais += aposta_atual;

            Simbolo grade[3][3];
            for(int i = 0; i < 3; i++) 
                for(int j = 0; j < 3; j++) 
                    grade[i][j] = simbolos[rand() % num_simbolos];

            for (int pisca = 0; pisca < 3; pisca++) {
                limparTela();
                for (int i = 0; i < 3; i++) {
                    char ascii[3][6][32];
                    for (int j = 0; j < 3; j++) {
                        Simbolo temp = simbolos[rand() % num_simbolos];
                        exibirSimboloAscii(temp.nome, ascii[j]);
                    }
                    for (int linha = 0; linha < 6; linha++) {
                        for (int j = 0; j < 3; j++) printf(" %s ", ascii[j][linha]);
                        printf("\n");
                    }
                    printf("\n");
                }
                pausar(300);
            }

            limparTela();
            printf("Creditos: R$ %.2f   |   Aposta: R$ %.2f\n", *creditos, aposta_atual);
            printf("--------------------------------------------------------\n");
            printf("Resultado Final:\n\n");

            for (int i = 0; i < 3; i++) {
                char ascii[3][6][32];
                for (int j = 0; j < 3; j++) {
                    exibirSimboloAscii(grade[i][j].nome, ascii[j]);
                }
                for (int linha = 0; linha < 6; linha++) {
                    for (int j = 0; j < 3; j++) printf(" %s ", ascii[j][linha]);
                    printf("\n");
                }
                printf("\n");
            }
            pausar(1000);

            double premio_rodada = 0;
            int linhas_vencedoras = 0;

            for(int i = 0; i < 3; i++) 
                if (strcmp(grade[i][0].nome, grade[i][1].nome) == 0 && strcmp(grade[i][1].nome, grade[i][2].nome) == 0) {
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
                printf("PARABENS! Voce acertou %d linha(s)!\n", linhas_vencedoras);
                *creditos += premio_rodada;
                rel->ganhos_totais += premio_rodada;
                rel->vitorias++;
            } else {
                printf("Nao foi dessa vez. Sem premios.\n");
                rel->derrotas++;
            }
            printf("Seus creditos agora: R$ %.2f / Vitoria de: R$ %.2f\n", *creditos, premio_rodada);
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
    printf("1. O objetivo e combinar 3 simbolos iguais em uma das 5 linhas de pagamento.\n");
    printf("2. As linhas de pagamento sao:\n");
    printf("   - As 3 linhas horizontais.\n");
    printf("   - As 2 linhas diagonais.\n");
    printf("3. O premio de cada linha vencedora e [VALOR DA APOSTA] x [MULTIPLICADOR DO SIMBOLO].\n\n");

    char mini[6][32];

    printf("4. Simbolos e multiplicadores:\n\n");

    exibirSimboloAscii("Cereja", mini);
    printf("\033[31mCereja  : 2x\n\033[0m");
    for(int i=0;i<3;i++){ printf("%s\n", mini[i]); }

    exibirSimboloAscii("Limao", mini);
    printf("\033[93mLimao   : 3x\n\033[0m");
    for(int i=0;i<3;i++){ printf("%s\n", mini[i]); }

    exibirSimboloAscii("Laranja", mini);
    printf("\033[33mLaranja : 5x\n\033[0m");
    for(int i=0;i<3;i++){ printf("%s\n", mini[i]); }

    exibirSimboloAscii("Bar", mini);
    printf("\033[97mBar     : 10x\n\033[0m");
    for(int i=0;i<3;i++){ printf("%s\n", mini[i]); }

    exibirSimboloAscii("Sete", mini);
    printf("\033[34mSete    : 25x\n\033[0m");
    for(int i=0;i<3;i++){ printf("%s\n", mini[i]); }

    exibirSimboloAscii("DIAMANTE", mini);
    printf("\033[36mDIAMANTE: 50x\n\033[0m");
    for(int i=0;i<3;i++){ printf("%s\n", mini[i]); }

    exibirSimboloAscii("SAHUR", mini);
    printf("\033[32mSAHUR   : 100x\n\033[0m");
    for(int i=0;i<3;i++){ printf("%s\n", mini[i]); }

    printf("\n=======================================================\n");
    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}

void exibirRelatorio(Relatorio rel, double creditos_iniciais) {
    limparTela();
    double balanco = rel.ganhos_totais - rel.perdas_totais;
    float taxa_vitoria = (rel.rodadas_jogadas > 0) ? ((float)rel.vitorias / rel.rodadas_jogadas) * 100.0f : 0.0f;

    printf("================= RELATORIO DE SESSAO =================\n\n");
    printf("Creditos Iniciais: R$ %.2f\n\n", creditos_iniciais);
    printf("Rodadas Jogadas: %d\n", rel.rodadas_jogadas);
    printf("Vitorias: %d\n", rel.vitorias);
    printf("Derrotas: %d\n", rel.derrotas);
    printf("Taxa de Vitoria: %.2f%%\n\n", taxa_vitoria);
    printf("Total Ganho (soma de premios): R$ %.2f\n", rel.ganhos_totais);
    printf("Total Apostado: R$ %.2f\n", rel.perdas_totais);
    printf("\n-------------------------------------------------------\n");
    printf("Balanco Final (Ganhos - Perdas): R$ %.2f\n", balanco);
    printf("=======================================================\n");
    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}

void depositar(double* creditos) {
    limparTela();
    double valor_deposito;
    printf("========= DEPOSITO DE CREDITOS =========\n\n");
    printf("Saldo atual: R$ %.2f\n", *creditos);
    printf("Digite o valor que deseja depositar (0 para cancelar): ");
    
    if (scanf("%lf", &valor_deposito) != 1) {
        printf("Valor invalido.\n");
        limparBufferEntrada();
    } else {
        limparBufferEntrada();
        if (valor_deposito < 0) {
            printf("Nao e possivel depositar um valor negativo.\n");
        } else if (valor_deposito > 0) {
            *creditos += valor_deposito;
            printf("\nDeposito de R$ %.2f realizado com sucesso!\n", valor_deposito);
            printf("Novo saldo: R$ %.2f\n", *creditos);
        }
    }
    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}

void sacar(double* creditos) {
    limparTela();
    double valor_saque;
    printf("========= SAQUE DE CREDITOS =========\n\n");
    printf("Saldo disponivel para saque: R$ %.2f\n", *creditos);
    printf("Digite o valor que deseja sacar (0 para cancelar): ");

    if (scanf("%lf", &valor_saque) != 1) {
        printf("Valor invalido.\n");
        limparBufferEntrada();
    } else {
        limparBufferEntrada();
        if (valor_saque < 0) {
            printf("Nao e possivel sacar um valor negativo.\n");
        } else if (valor_saque > *creditos) {
            printf("Valor de saque maior que o saldo disponivel.\n");
        } else if (valor_saque > 0) {
            *creditos -= valor_saque;
            printf("\nSaque de R$ %.2f realizado com sucesso!\n", valor_saque);
            printf("Saldo restante: R$ %.2f\n", *creditos);
        }
    }
}

