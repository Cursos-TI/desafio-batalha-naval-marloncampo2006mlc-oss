#include <cmath>
#include <stdio.h>

int main() {
    // ======= Tabuleiro 10x10 =======
    int tabuleiro[10][10] = {0};

    // ======= Navios =======
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};

    // ======= Coordenadas dos navios =======
    int linha1 = 2, coluna1 = 3;
    int linha2 = 5, coluna2 = 6;
    int linha3 = 1, coluna3 = 1;
    int linha4 = 4, coluna4 = 8;

    // ======= Posicionamento dos navios =======
    for (int i = 0; i < 3; i++) {
        if (coluna1 + i < 10) tabuleiro[linha1][coluna1 + i] = navio1[i];
        if (linha2 + i < 10) tabuleiro[linha2 + i][coluna2] = navio2[i];
        if (linha3 + i < 10 && coluna3 + i < 10) tabuleiro[linha3 + i][coluna3 + i] = navio3[i];
        if (linha4 + i < 10 && coluna4 - i >= 0) tabuleiro[linha4 + i][coluna4 - i] = navio4[i];
    }

    // ======= Matrizes de Habilidade (5x5) =======
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // ======= Habilidade: Cone (↧) =======
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i && i < 3)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // ======= Habilidade: Cruz (+) =======
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // ======= Habilidade: Octaedro (losango) =======
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ======= Pontos de origem no tabuleiro =======
    int origemCone[2] = {2, 2};
    int origemCruz[2] = {6, 4};
    int origemOctaedro[2] = {5, 8};

    
    for (int tipo = 0; tipo < 3; tipo++) {
        int (*habilidade)[5];
        int origemLinha, origemColuna;

        if (tipo == 0) {
            habilidade = cone;
            origemLinha = origemCone[0];
            origemColuna = origemCone[1];
        } else if (tipo == 1) {
            habilidade = cruz;
            origemLinha = origemCruz[0];
            origemColuna = origemCruz[1];
        } else {
            habilidade = octaedro;
            origemLinha = origemOctaedro[0];
            origemColuna = origemOctaedro[1];
        }

        // sobreposição centralizada
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (habilidade[i][j] == 1) {
                    int linhaTab = origemLinha - 2 + i;
                    int colunaTab = origemColuna - 2 + j;

                    if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
                        if (tabuleiro[linhaTab][colunaTab] == 0) {
                            tabuleiro[linhaTab][colunaTab] = 5;
                        }
                    }
                }
            }
        }
    }

    // ======= Exibição do Tabuleiro =======
    printf("=== TABULEIRO BATALHA NAVAL COM HABILIDADES ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
