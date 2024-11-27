#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~';
        }
    }
}


void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("  0 1 2 3 4\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


void posicionarNavio(char tabuleiro[TAM][TAM]) {
    srand(time(NULL)); 
    int linha = rand() % TAM;
    int coluna = rand() % TAM;
    tabuleiro[linha][coluna] = 'N'; 
}


int realizarAtaque(char tabuleiro[TAM][TAM], int linha, int coluna) {
    if (tabuleiro[linha][coluna] == 'N') {
        tabuleiro[linha][coluna] = 'X'; 
        return 1;
    } else {
        tabuleiro[linha][coluna] = 'O';
        return 0; 
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    int linha, coluna;
    int acertos = 0;
    int maxTentativas = 5;
    int tentativas = 0;

    inicializarTabuleiro(tabuleiro);  
    posicionarNavio(tabuleiro);  

    printf("Bem-vindo ao jogo de Batalha Naval!\n");

    while (tentativas < maxTentativas && acertos < 1) {
        exibirTabuleiro(tabuleiro);  
        printf("Tentativa %d de %d\n", tentativas + 1, maxTentativas);
        

        printf("Digite a linha e a coluna (0-4) para atacar: ");
        scanf("%d %d", &linha, &coluna);


        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("Coordenada inválida. Tente novamente.\n");
            continue;
        }

       
        if (realizarAtaque(tabuleiro, linha, coluna)) {
            printf("Acertou! Você afundou o navio!\n");
            acertos = 1; 
        } else {
            printf("Errou! Tente novamente.\n");
        }

        tentativas++;  
    }

    if (acertos == 0) {
        printf("Você não conseguiu afundar o navio. Fim de jogo.\n");
    } else {
        printf("Você venceu o jogo! O navio foi afundado.\n");
    }

    return 0;
}
