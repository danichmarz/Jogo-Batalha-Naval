#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializar o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navios horizontais e verticais
    int navio1[TAM_NAVIO] = {3, 3, 3}; // Horizontal
    int navio2[TAM_NAVIO] = {3, 3, 3}; // Vertical

    // Navios diagonais
    int navio3[TAM_NAVIO] = {3, 3, 3}; // Diagonal principal
    int navio4[TAM_NAVIO] = {3, 3, 3}; // Diagonal secundária

    // Posição navio horizontal (linha 2, colunas 3 a 5)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[2][3 + i] = navio1[i];
    }

    // Posição navio vertical (coluna 1, linhas 5 a 7)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[5 + i][1] = navio2[i];
    }

    // Posição navio diagonal principal (linha 0 a 2, coluna 0 a 2)
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[i][i] == 0) {
            tabuleiro[i][i] = navio3[i];
        }
    }

    // Posição navio diagonal secundária (linha 0 a 2, coluna 9 a 7)
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[i][9 - i] == 0) {
            tabuleiro[i][9 - i] = navio4[i];
        }
    }

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}