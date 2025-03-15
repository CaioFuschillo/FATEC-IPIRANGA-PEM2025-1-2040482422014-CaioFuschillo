/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Alterações no código da atividade*
* 2 para melhorar a eficiência do programa com modulari- *
* zação e utilizando ponteiros.                          *
* Data - 14/03/2025                                      * 
* Autor: Caio Fuschillo                                  *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define NUM_RUAS 3
#define NUM_GONDOLAS 10
#define TAM_PRODUTO 10

// Função para estocar um produto
void estocar_produto(char estoque[NUM_RUAS][NUM_GONDOLAS][TAM_PRODUTO], char produto[TAM_PRODUTO], char rua, int gondola) {
    int rua_index = rua - 'A'; // Convertendo a letra da rua para índice (A = 0, B = 1, C = 2)
    
    if (strlen(estoque[rua_index][gondola]) == 0) { // Se a posição estiver vazia
        strcpy(estoque[rua_index][gondola], produto); // Estocar o produto
        printf("Produto %s estocado na Gondola %c%d\n", produto, rua, gondola);
    } else {
        printf("Erro: Gondola %c%d ja esta ocupada.\n", rua, gondola);
    }
}

// Função para retirar um produto
void retirar_produto(char estoque[NUM_RUAS][NUM_GONDOLAS][TAM_PRODUTO], char produto[TAM_PRODUTO]) {
    int encontrado = 0;
    for (int i = 0; i < NUM_RUAS; i++) {
        for (int j = 0; j < NUM_GONDOLAS; j++) {
            if (strcmp(estoque[i][j], produto) == 0) { // Se o produto for encontrado
                printf("Produto %s retirado da Gondola %c%d\n", produto, 'A' + i, j);
                estoque[i][j][0] = '\0'; // Limpar a gôndola (retirar o produto)
                encontrado = 1;
                break;
            }
        }
        if (encontrado) break;
    }
    if (!encontrado) {
        printf("Erro: Produto %s nao encontrado no estoque.\n", produto);
    }
}

// Função para exibir o menu de opções
void exibir_menu() {
    printf("\nEscolha a operacao:\n");
    printf("1. Estocar produto\n");
    printf("2. Retirar produto\n");
    printf("0. Sair\n");
    printf("Opcao: ");
}

// Função para inicializar o estoque (todas as gôndolas começam vazias)
void inicializar_estoque(char estoque[NUM_RUAS][NUM_GONDOLAS][TAM_PRODUTO]) {
    for (int i = 0; i < NUM_RUAS; i++) {
        for (int j = 0; j < NUM_GONDOLAS; j++) {
            estoque[i][j][0] = '\0'; // Gôndolas começam vazias
        }
    }
}

// Função principal que controla o fluxo do programa
int main() {
    char estoque[NUM_RUAS][NUM_GONDOLAS][TAM_PRODUTO]; // Estoque de 3 ruas e 10 gôndolas
    int opcao;
    char produto[TAM_PRODUTO];
    char rua;
    int gondola;
    
    // Inicializa o estoque
    inicializar_estoque(estoque);

    while (1) {
        // Exibe o menu e lê a opção do usuário
        exibir_menu();
        scanf("%d", &opcao);
        
        if (opcao == 0) {
            break; // Sai do programa
        } else if (opcao == 1) {
            // Estocar produto
            printf("Digite o codigo do produto: ");
            scanf("%s", produto);
            printf("Digite a rua (A, B ou C): ");
            scanf(" %c", &rua);
            printf("Digite o numero da gondola (1 a 10): ");
            scanf("%d", &gondola);
            
            if (gondola < 1 || gondola > 10) {
                printf("Erro: Gondola invalida! Deve ser entre 1 e 10.\n");
            } else {
                estocar_produto(estoque, produto, rua, gondola - 1); // Ajuste para índice de 0 a 9
            }
        } else if (opcao == 2) {
            // Retirar produto
            printf("Digite o codigo do produto a ser retirado: ");
            scanf("%s", produto);
            retirar_produto(estoque, produto);
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
    
    return 0;
}
