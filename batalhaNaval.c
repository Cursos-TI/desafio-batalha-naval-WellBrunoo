#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define OCUPADO 3
#define AGUA 0

int main() {
    // Declaração da matriz do tabuleiro e inicialização com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas do navio horizontal (linha, coluna)
    int linhaH = 2, colunaH = 4;

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = OCUPADO;
        }
    } else {
        printf("Erro: o navio horizontal não cabe no tabuleiro.\n");
        return 1;
    }

    // Coordenadas do navio vertical (linha, coluna)
    int linhaV = 5, colunaV = 7;
    int sobreposicao = 0;

    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == OCUPADO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = OCUPADO;
            }
        } else {
            printf("Erro: o navio vertical se sobrepõe ao navio horizontal.\n");
            return 1;
        }
    } else {
        printf("Erro: o navio vertical não cabe no tabuleiro.\n");
        return 1;
    }

    // Exibição do cabeçalho (letras A–J para colunas)
    printf("\n    ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Exibição do tabuleiro com coordenadas (linhas numeradas)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d |", i + 1);  // Números da linha com barra separadora
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
