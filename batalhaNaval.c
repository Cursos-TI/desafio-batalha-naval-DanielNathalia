#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TAMANHO 10
#define tamanhoNavio 2
#define TAMANHO_TABULEIRO 15

// Função para verificar se uma posição está dentro dos limites
bool estaDentroDosLimites(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO;
}

// Função para verificar se há sobreposição
bool validaPosicao(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}


void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Inicializando com água (valor 0)
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
 for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibindo cada posição do tabuleiro
        }
        printf("\n"); // Quebra de linha para formar o tabuleiro visualmente
    }
}


//Matriz Cone
void criarMatrizCone(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int distancia = abs(j - centro) + i;
            matriz[i][j] = (j >= centro - i && j <= centro + i) ? 1 : 0;
        }
    }
}

//Matriz Cruz
void criarMatrizCruz(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
           matriz[i][j] = (i == centro || j == centro) ? 1 : 0;
        }
    }
}

//Matriz Octaedro
void criarMatrizOctaedro(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int distancia = abs(i - centro) + abs(j - centro);
            matriz[i][j] = (distancia <= centro) ? 1 : 0; // Área em forma de octaedro
        }
    }
}

void imprimirMatriz(int tamanho, int matriz[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}


//Posição Navio Horizontal
int posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (coluna + tamanhoNavio > TAMANHO) {
        return 0; // Verifica se cabe horizontalmente no tabuleiro
    }
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha][coluna + i] = 3; // Posiciona o navio horizontal
    }
    return 1;
}
//Posição Navio Vertical
int posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + tamanhoNavio > TAMANHO) {
        return 0; // Verifica se cabe verticalmente no tabuleiro
    }
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha + i][coluna] = 3; // Posiciona o navio vertical
    }
    return 1; // Sucesso
}
//Posição Navio Diagonal
int posicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (coluna + linha + tamanhoNavio > TAMANHO) {
        return 0; // Verifica se cabe diagonalmente no tabuleiro
    }
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha + i][coluna + i] = 3; // Posiciona o navio diagonalmente
    }
    return 1;
}

//Integrar tabuleiros
void integrarHabilidadeAoTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],int habilidade[][7], int tamanhoHabilidade, int origemX, int origemY) {
    int inicioX = origemX - tamanhoHabilidade / 2;
    int inicioY = origemY - tamanhoHabilidade / 2;

    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            int x = inicioX + i;
            int y = inicioY + j;

            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && habilidade[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca as áreas afetadas pela habilidade com o valor 5
            }
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}





int main() {

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    memset(tabuleiro, 0, sizeof(tabuleiro));
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

    printf("\n");


    int tamanho = 7;
    int matrizCone[tamanho][tamanho];
    int matrizCruz[tamanho][tamanho];
    int matrizOctaedro[tamanho][tamanho];

    //Criando as matrizes
    criarMatrizCone(tamanho, matrizCone);
    criarMatrizCruz(tamanho, matrizCruz);
    criarMatrizOctaedro(tamanho, matrizOctaedro);

    //Imprimindo as matrizes

    printf("***Matriz Cone***\n");
    imprimirMatriz(tamanho, matrizCone);
    printf("\n***Matriz Cruz***\n");
    imprimirMatriz(tamanho, matrizCruz);
    printf("\n***Matriz Octaedro***\n");
    imprimirMatriz(tamanho, matrizOctaedro);

// Integração das habilidades no tabuleiro
    integrarHabilidadeAoTabuleiro(tabuleiro, matrizCone, 7, 4, 4);     // Exemplo: Cone no ponto (4,4)
    integrarHabilidadeAoTabuleiro(tabuleiro, matrizCruz, 7, 10, 10);  // Exemplo: Cruz no ponto (10,10)
    integrarHabilidadeAoTabuleiro(tabuleiro, matrizOctaedro, 7, 7, 7); // Exemplo: Octaedro no ponto (7,7)

    // Imprime o tabuleiro resultante
    printf("***Tabuleiro com habilidades integradas***\n");
    imprimirTabuleiro(tabuleiro);


    return 0;
}
