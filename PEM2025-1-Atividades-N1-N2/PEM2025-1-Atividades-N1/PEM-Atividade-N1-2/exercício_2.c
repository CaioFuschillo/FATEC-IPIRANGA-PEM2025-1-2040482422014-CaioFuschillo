/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Controle de um estoque para um   *
* armazém                                                *
* Data - 07/03/2025                                      * 
* Autor: Caio Fuschillo                                  *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define NUM_RUAS 3
#define NUM_GONDOLAS 10

// Funcao para estocar o produto
void estocar_produto(char estoque[NUM_RUAS][NUM_GONDOLAS][10], char produto[10], char rua, int gondola) {
    int rua_index = rua - 'A'; // Convertendo a letra da rua para indice (A = 0, B = 1, C = 2)
    
    if (strlen(estoque[rua_index][gondola]) == 0) { // Se a posicao estiver vazia
        strcpy(estoque[rua_index][gondola], produto); // Estocar o produto
        printf("Produto %s estocado na Gondola %c%d\n", produto, rua, gondola);
    } else {
        printf("Erro: Gondola %c%d ja esta ocupada.\n", rua, gondola);
    }
}

// Funcao para retirar o produto
void retirar_produto(char estoque[NUM_RUAS][NUM_GONDOLAS][10], char produto[10]) {
    int encontrado = 0;
    for (int i = 0; i < NUM_RUAS; i++) {
        for (int j = 0; j < NUM_GONDOLAS; j++) {
            if (strcmp(estoque[i][j], produto) == 0) { // Se o produto for encontrado
                printf("Produto %s retirado da Gondola %c%d\n", produto, 'A' + i, j);
                estoque[i][j][0] = '\0'; // Limpar a gondola (retirar o produto)
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

int main() {
    // Inicializar o estoque (todas as gôndolas começam vazias)
    char estoque[NUM_RUAS][NUM_GONDOLAS][10] = { { { '\0' } } }; // Matriz de 3x10 com strings vazias
    
    int opcao;
    char produto[10];
    char rua;
    int gondola;
    
    while (1) {
        // Menu de opcoes
        printf("\nEscolha a operacao:\n");
        printf("1. Estocar produto\n");
        printf("2. Retirar produto\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 0) {
            break;
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
                estocar_produto(estoque, produto, rua, gondola - 1); // Ajuste para indice de 0 a 9
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
