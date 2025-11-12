#include <stdio.h>

int main() {
    // ======= Tabuleiro 10x10 =======
    int tabuleiro[10][10] = {0};

    // ======= Navios =======
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // ======= Coordenadas iniciais =======
    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical = 5, colunaVertical = 7;

    // ======= Posicionamento do Navio Horizontal =======
    for (int i = 0; i < 3; i++) {
        if (colunaHorizontal + i < 10) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    }

    // ======= Posicionamento do Navio Vertical =======
    for (int i = 0; i < 3; i++) {
        if (linhaVertical + i < 10) {
            
            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }
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
