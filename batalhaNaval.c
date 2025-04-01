#include <stdio.h>
#include <stdbool.h>

#define tamanho 10
#define tamanhoNavio 2


// Função para verificar se uma posição está dentro dos limites
bool estaDentroDosLimites(int linha, int coluna) {
    return linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho;
}

// Função para verificar se há sobreposição
bool validaPosicao(int tabuleiro[tamanho][tamanho], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}


void inicializarTabuleiro(int tabuleiro[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0; // Inicializando com água (valor 0)
        }
    }
}
//Posição Navio Horizontal
int posicionarNavioHorizontal(int tabuleiro[tamanho][tamanho], int linha, int coluna) {
    if (coluna + tamanhoNavio > tamanho) {
        return 0; // Verifica se cabe horizontalmente no tabuleiro
    }
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha][coluna + i] = 3; // Posiciona o navio horizontal
    }
    return 1;
}
//Posição Navio Vertical
int posicionarNavioVertical(int tabuleiro[tamanho][tamanho], int linha, int coluna) {
    if (linha + tamanhoNavio > tamanho) {
        return 0; // Verifica se cabe verticalmente no tabuleiro
    }
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha + i][coluna] = 3; // Posiciona o navio vertical
    }
    return 1; // Sucesso
}
//Posição Navio Diagonal
int posicionarNavioDiagonal(int tabuleiro[tamanho][tamanho], int linha, int coluna) {
    if (coluna + linha + tamanhoNavio > tamanho) {
        return 0; // Verifica se cabe diagonalmente no tabuleiro
    }
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha + i][coluna + i] = 3; // Posiciona o navio diagonalmente
    }
    return 1;
}


void exibirTabuleiro(int tabuleiro[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; i++) {
 for (int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibindo cada posição do tabuleiro
        }
        printf("\n"); // Quebra de linha para formar o tabuleiro visualmente
    }
}

int main() {
    int tabuleiro[tamanho][tamanho];
    inicializarTabuleiro(tabuleiro);
// Coordenadas iniciais dos navios (definidas diretamente no código)
    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical = 5, colunaVertical = 1;
    int linhaDiagonal = 4, colunaDiagonal= 2;

    if (!posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        printf("Navio horizontal não pode ser posicionado nas coordenadas (%d, %d).\n", linhaHorizontal, colunaHorizontal);
    }

    if (!posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical)) {
        printf("Navio vertical não pode ser posicionado nas coordenadas (%d, %d).\n", linhaVertical, colunaVertical);
    }
    if (!posicionarNavioDiagonal(tabuleiro, linhaDiagonal, colunaDiagonal)) {
        printf("Navio Diagonal não pode ser posicionado nas coordenadas (%d, %d).\n", linhaDiagonal, colunaDiagonal);
    }

    printf("***Batalha Naval***\n");
    exibirTabuleiro(tabuleiro);




    return 0;
}
