#include <stdio.h>

#define TAM 10
#define TAM_HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][3 + i] = 3;
    }

    // Navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[5 + i][1] = 3;
    }

    // Diagonal principal
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][i] == 0) {
            tabuleiro[i][i] = 3;
        }
    }

    // Diagonal secundária
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][9 - i] == 0) {
            tabuleiro[i][9 - i] = 3;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemX, int origemY) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = origemX - TAM_HABILIDADE / 2 + i;
            int coluna = origemY - TAM_HABILIDADE / 2 + j;

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

void gerarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i >= j - TAM_HABILIDADE / 2 && i >= TAM_HABILIDADE / 2 - j) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void gerarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void gerarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro com habilidades:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    gerarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 1, 5);

    gerarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);

    gerarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 7, 2);

    exibirTabuleiro(tabuleiro);

    return 0;
}