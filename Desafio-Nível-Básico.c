#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3

// Função para exibir o tabuleiro
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

    // Inicializando o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navios representados por 3
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais para os navios (definidas no código)
    int linhaH = 2; // linha para navio horizontal
    int colunaH = 4;

    int linhaV = 5; // linha para navio vertical
    int colunaV = 1;

    // Validação de limites do navio horizontal
    if (colunaH + TAM_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    } else {
        printf("Navio horizontal ultrapassa os limites do tabuleiro!\n");
    }

    // Validação de limites do navio vertical e sobreposição
    int podeInserir = 1;
    if (linhaV + TAM_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podeInserir = 0; // sobreposição detectada
                break;
            }
        }

        if (podeInserir) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        } else {
            printf("Navio vertical está sobrepondo outro navio!\n");
        }
    } else {
        printf("Navio vertical ultrapassa os limites do tabuleiro!\n");
    }

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
