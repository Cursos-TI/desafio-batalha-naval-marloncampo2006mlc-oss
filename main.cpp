#include <stdio.h>

int main() {
    // ======= Tabuleiro 10x10 =======
    int tabuleiro[10][10] = {0};

    // ======= Navios =======
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};

    // ======= Coordenadas iniciais =======
    int linha1 = 2, coluna1 = 3;
    int linha2 = 5, coluna2 = 6;
    int linha3 = 1, coluna3 = 1;
    int linha4 = 4, coluna4 = 8;

    // ======= Navio Horizontal =======
    for (int i = 0; i < 3; i++) {
        if (coluna1 + i < 10 && tabuleiro[linha1][coluna1 + i] == 0) {
            tabuleiro[linha1][coluna1 + i] = navio1[i];
        }
    }

    // ======= Navio Vertical =======
    for (int i = 0; i < 3; i++) {
        if (linha2 + i < 10 && tabuleiro[linha2 + i][coluna2] == 0) {
            tabuleiro[linha2 + i][coluna2] = navio2[i];
        }
    }

    // ======= Navio Diagonal Principal (↘) =======
    for (int i = 0; i < 3; i++) {
        if (linha3 + i < 10 && coluna3 + i < 10 && tabuleiro[linha3 + i][coluna3 + i] == 0) {
            tabuleiro[linha3 + i][coluna3 + i] = navio3[i];
        }
    }

    // ======= Navio Diagonal Secundária (↙) =======
    for (int i = 0; i < 3; i++) {
        if (linha4 + i < 10 && coluna4 - i >= 0 && tabuleiro[linha4 + i][coluna4 - i] == 0) {
            tabuleiro[linha4 + i][coluna4 - i] = navio4[i];
        }
    }

    // ======= Exibição do Tabuleiro =======
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
