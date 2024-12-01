#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 5
#define MAX_JOGADORES 2
#define MAX_NOME 50

void inicializarTabuleiro(char tabuleiro[TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            tabuleiro[i][j] = 0; // 0 significa água, 1 significa barco
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAM][TAM])
{
    printf("  0 1 2 3 4\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++)
        {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(char tabuleiro[TAM][TAM])
{
    srand(time(NULL));
    int linha = rand() % TAM;
    int coluna = rand() % TAM;
    tabuleiro[linha][coluna] = 'N';
}

int realizarAtaque(char tabuleiro[TAM][TAM], int linha, int coluna)
{
    if (tabuleiro[linha][coluna] == 'N')
    {
        tabuleiro[linha][coluna] = 'X';
        return 1;
    }
    else
    {
        tabuleiro[linha][coluna] = 'O';
        return 0;
    }
}

int main()
{
    char tabuleiro[TAM][TAM];
    int linha, coluna;
    int acertos = 0;
    int maxTentativas = 5;
    int tentativas = 0;
    char jogadores[MAX_JOGADORES][MAX_NOME];
    int jogadorAtual = 0;

    // Registrar jogadores
    for (int i = 0; i < MAX_JOGADORES; i++)
    {
        printf("Digite o nome do jogador %d: ", i + 1);
        fgets(jogadores[i], MAX_NOME, stdin);
        jogadores[i][strcspn(jogadores[i], "\n")] = '\0'; // Remover nova linha
    }

    inicializarTabuleiro(tabuleiro);
    posicionarNavio(tabuleiro);

    printf("Bem-vindo ao jogo de Batalha Naval!\n");

    while (tentativas < maxTentativas && acertos < 1)
    {
        exibirTabuleiro(tabuleiro);
        printf("Tentativa %d de %d\n", tentativas + 1, maxTentativas);
        printf("Vez do jogador: %s\n", jogadores[jogadorAtual]);

        printf("Digite a linha e a coluna (0-4) para atacar: ");
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM)
        {
            printf("Coordenada inválida. Tente novamente.\n");
            continue;
        }

        if (realizarAtaque(tabuleiro, linha, coluna))
        {
            printf("Acertou! Você afundou o navio!\n");
            acertos = 1;
        }
        else
        {
            printf("Errou! Tente novamente.\n");
        }

        tentativas++;
        jogadorAtual = (jogadorAtual + 1) % MAX_JOGADORES; // Alternar entre jogadores
    }

    if (acertos == 0)
    {
        printf("Nenhum jogador conseguiu afundar o navio. Fim de jogo.\n");
    }
    else
    {
        printf("O jogador %s venceu o jogo! O navio foi afundado.\n", jogadores[jogadorAtual]);
    }

    return 0;
}