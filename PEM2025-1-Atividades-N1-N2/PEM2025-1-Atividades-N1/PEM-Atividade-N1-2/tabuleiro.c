/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Programa de um jogo da velha     *
* Data - 07/03/2025                                      * 
* Autor: Caio Fuschillo                                  *
*--------------------------------------------------------*/
#include <stdio.h>

#define TAM 3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = ' '; // Inicializa todas as posições com espaço
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAM - 1) printf("|");
        }
        printf("\n");
        if (i < TAM - 1) printf("---|---|---\n");
    }
}

// Função para verificar se há um vencedor
int verificarVencedor(char tabuleiro[TAM][TAM]) {
    // Verificar linhas e colunas
    for (int i = 0; i < TAM; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return 1; // Linha
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return 1; // Coluna
    }
    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return 1; // Diagonal principal
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return 1; // Diagonal secundária

    return 0; // Não há vencedor ainda
}

// Função para verificar se o jogo terminou em empate
int verificarEmpate(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0; // Ainda existem espaços vazios, jogo não terminou
            }
        }
    }
    return 1; // Se não há espaços vazios, é empate
}

// Função para realizar uma jogada
int fazerJogada(char tabuleiro[TAM][TAM], int linha, int coluna, char jogador) {
    if (tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = jogador;
        return 1; // Jogada válida
    } else {
        return 0; // A posição já está ocupada
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    int linha, coluna;
    int turno = 0;
    char jogadorAtual = 'X'; // Começa com o jogador 'X'

    inicializarTabuleiro(tabuleiro);

    while (1) {
        exibirTabuleiro(tabuleiro);
        
        // Solicitar jogada
        printf("\nJogador %c, digite a linha (0-2) e a coluna (0-2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        // Verificar se a jogada é válida
        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM || !fazerJogada(tabuleiro, linha, coluna, jogadorAtual)) {
            printf("Jogada invalida! Tente novamente.\n");
            continue;
        }

        // Verificar se há vencedor
        if (verificarVencedor(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("\nParabens, Jogador %c venceu!\n", jogadorAtual);
            break;
        }

        // Verificar empate
        if (verificarEmpate(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("\nEmpate! O jogo terminou sem vencedor.\n");
            break;
        }

        // Trocar de jogador
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    return 0;
}

