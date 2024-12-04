#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 10             //variavel pra definir o tamanho do tabuleiro
#define MAX_JOGADORES 2    //numero de jogadores
#define MAX_NOME 20        //tamanho maximo do nome dos jogadores

int pontosJogador1 = 0;
int pontosJogador2 = 0;

void inicializarTabuleiro(char tabuleiro[TAM][TAM])
// Define o tamanho do tabuleiro(matriz char)
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            tabuleiro[i][j] = '~';
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAM][TAM])
// Exibe o tabuleiro na tela 
{
    printf("  0 1 2 3 4 5 6 7 8 9\n");
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

void posicionarNavio(char tabuleiro[TAM][TAM], char *jogadorA, char *jogadorB)
// funcao para input da posicao dos navios pelos jogadores
{
    int linha, coluna;
    for (int i = 0; i < 4; i++)
    {
        printf("\nJogador %s, posicione o navio %d\n", jogadorA, i + 1);
        printf("Digite a linha e a coluna (0-10): ");
        scanf("%d %d", &linha, &coluna);
        if (tabuleiro[linha][coluna] != '~')
        {
            printf("Posição já ocupada. Tente novamente.\n");
            i--;
            continue;
        }
        tabuleiro[linha][coluna] = 'A' + i;
    }
    for (int i = 0; i < 4; i++)
    {
        printf("Jogador %s, posicione o navio %d\n", jogadorB, i + 1);
        printf("Digite a linha e a coluna (0-10): ");
        scanf("%d %d", &linha, &coluna);
        if (tabuleiro[linha][coluna] != '~')
        {
            printf("Posição já ocupada. Tente novamente.\n");
            i--;
            continue;
        }
        tabuleiro[linha][coluna] = 'E' + i;
    }
}

int realizarAtaque(char tabuleiro[TAM][TAM], int linha, int coluna, int jogadorAtual)
// realiza o ataque e trata o input de acordo com a vez do jogador e as condicoes do jogo
{
    // tratamento de jogadas do jogador 1
    if (jogadorAtual == 1)
    {
        if (tabuleiro[linha][coluna] != '~' && tabuleiro[linha][coluna] != 'X')
        {
            if (tabuleiro[linha][coluna] == 'A')
            {
                tabuleiro[linha][coluna] = 'X';
                pontosJogador2 += 1;
                printf("Acertou um navio inimigo! \n");
            }
            if (tabuleiro[linha][coluna] == 'B')
            {
                tabuleiro[linha][coluna] = 'X';
                pontosJogador2 += 2;
                printf("Acertou um navio inimigo! \n");
            }
            if (tabuleiro[linha][coluna] == 'C')
            {
                tabuleiro[linha][coluna] = 'X';
                pontosJogador2 += 3;
                printf("Acertou um navio inimigo! \n");
            }
            if (tabuleiro[linha][coluna] == 'D')
            {
                tabuleiro[linha][coluna] = 'X';
                pontosJogador2 += 4;
                printf("Acertou um navio inimigo! \n");
            }
            return 1;
        }
        else
        {
            printf("\n\nErrou! Tente novamente.\n\n");
            return 0;
        }
    }
// tratamento de jogadas do jogador 0
    if (jogadorAtual == 0)
    {
        if (tabuleiro[linha][coluna] != '~' && tabuleiro[linha][coluna] != 'X')
        {
            if (tabuleiro[linha][coluna] == 'E')
            {
                tabuleiro[linha][coluna] = 'X';
                pontosJogador1 += 1;
                printf("Acertou um navio inimigo! \n");
            }
            if (tabuleiro[linha][coluna] == 'F')
            {
                tabuleiro[linha][coluna] = 'X';
                pontosJogador1 += 2;
                printf("Acertou um navio inimigo! \n");
            }
            if (tabuleiro[linha][coluna] == 'G')
            {
                tabuleiro[linha][coluna] = 'X';
                pontosJogador1 += 3;
                printf("Acertou um navio inimigo! \n");
            }
            if (tabuleiro[linha][coluna] == 'H')
            {
                tabuleiro[linha][coluna] = 'X';
                pontosJogador1 += 4;
                printf("Acertou um navio inimigo! \n");
            }
            return 1;
        }
        else
        {
            printf("\n\nErrou! Tente novamente.\n\n");
            return 0;
        }
    }
}

int main() 
// No main() vamos fazer o jogo funcionar, enquanto os elementos e ações do jogo, é puxada atraves das funções criadas
{
    char tabuleiro[TAM][TAM];// o tabuleiro precisa ser uma matriz, e para manipular, precisamos de 2 laços de repetição
    int linha, coluna;
    int maxTentativas = 8; // 4 para cada jogador
    int tentativas = 0;
    char jogadores[MAX_JOGADORES][MAX_NOME];// primeiro indice é numero de jogadores, e o segundo qtd de caracteres para os nomes
    int jogadorAtual = 0;

    printf("Bem-vindo ao jogo de Batalha Naval!\n");
    // Registrar jogadores
    for (int i = 0; i < MAX_JOGADORES; i++)
    {
        printf("Digite o nome do jogador %d: ", i + 1);
        fgets(jogadores[i], MAX_NOME, stdin);
        jogadores[i][strcspn(jogadores[i], "\n")] = '\0'; // Remover nova linha
    }

    inicializarTabuleiro(tabuleiro);
    posicionarNavio(tabuleiro, jogadores[0], jogadores[1]);

    printf("O jogo começou! Tente acertar o navio inimigo:\n");

    while (tentativas < maxTentativas)
    {
        exibirTabuleiro(tabuleiro);
        printf("\nTentativa %d de %d\n", tentativas + 1, maxTentativas);
        printf("Vez do jogador: %s\n\n", jogadores[jogadorAtual]);

        printf("Digite a linha e a coluna (0-4) para atacar: ");
        scanf("%d %d", &linha, &coluna);

        realizarAtaque(tabuleiro, linha, coluna, jogadorAtual);
        printf("Pontos do %s: %d\n", jogadores[0], pontosJogador1);
        printf("Pontos do %s: %d\n\n\n", jogadores[1], pontosJogador2);

        tentativas++;
        if (jogadorAtual == 0)
        {
            jogadorAtual = 1;
        }
        else
        {
            jogadorAtual = 0;
        }
    }

    if (pontosJogador1 > pontosJogador2)
    {
        printf("O jogador %s venceu!\n", jogadores[0]);
    }
    else if (pontosJogador1 < pontosJogador2)
    {
        printf("O jogador %s venceu!\n", jogadores[1]);
    }
    else
    {
        printf("Os dois jogadores pontuaram igual!\n");
    }

    printf("\n\nFim de jogo.\n");

    return 0;
}
