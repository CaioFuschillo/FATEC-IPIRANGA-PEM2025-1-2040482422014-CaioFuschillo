/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Armazenar notas para residência  *
* e apresentar os 15 melhores candidatos                 *
* Data - 26/02/2025                                      * 
* Autor: Caio Fuschillo                                  *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float nota_final;
} Candidato;

int comparar(const void *a, const void *b) {
    Candidato *candidatoA = (Candidato *)a;
    Candidato *candidatoB = (Candidato *)b;

    if (candidatoA->nota_final < candidatoB->nota_final) {
        return 1;
    } else if (candidatoA->nota_final > candidatoB->nota_final) {
        return -1;
    } else {
        return 0;
    }
}

float calcular_media(float notas[], int num_notas) {
    float soma = 0, maior = notas[0], menor = notas[0];
    
    for (int i = 1; i < num_notas; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }

    for (int i = 0; i < num_notas; i++) {
        soma += notas[i];
    }

    return (soma - maior - menor) / (num_notas - 2);
}

float obter_nota_valida(char tipo_avaliacao[], int indice) {
    float nota;
    while (1) {
        printf("Digite a %d nota de %s (entre 0.0 e 10.0): ", indice, tipo_avaliacao);
        scanf("%f", &nota);
        if (nota >= 0.0 && nota <= 10.0) {
            return nota;
        } else {
            printf("Nota invalida! A nota deve ser entre 0.0 e 10.0.\n");
        }
    }
}

int main() {
    Candidato candidatos[50];
    float notas_PE[4], notas_AC[5], notas_PP[10], notas_EB[3];
    int num_candidatos, contador1, contador2;

    while (1) {
        printf("Digite o numero de candidatos (maximo 50): ");
        scanf("%d", &num_candidatos);
        
        if (num_candidatos > 0 && num_candidatos <= 50) {
            break;
        } else {
            printf("Numero invalido! O numero de candidatos deve ser entre 1 e 50.\n");
        }
    }

    for (contador1 = 0; contador1 < num_candidatos; contador1++) {
        printf("\nDigite o nome do candidato %d: ", contador1 + 1);
        scanf(" %49[^\n]", candidatos[contador1].nome);

        printf("Digite as 4 notas de Prova Escrita (PE):\n");
        for (contador2 = 0; contador2 < 4; contador2++) {
            notas_PE[contador2] = obter_nota_valida("Prova Escrita (PE)", contador2 + 1);
        }

        printf("Digite as 5 notas de Analise Curricular (AC):\n");
        for (contador2 = 0; contador2 < 5; contador2++) {
            notas_AC[contador2] = obter_nota_valida("Analise Curricular (AC)", contador2 + 1);
        }

        printf("Digite as 10 notas de Prova Pratica (PP):\n");
        for (contador2 = 0; contador2 < 10; contador2++) {
            notas_PP[contador2] = obter_nota_valida("Prova Practica (PP)", contador2 + 1);
        }

        printf("Digite as 3 notas de Entrevista em Banca Avaliadora (EB):\n");
        for (contador2 = 0; contador2 < 3; contador2++) {
            notas_EB[contador2] = obter_nota_valida("Entrevista em Banca Avaliadora (EB)", contador2 + 1);
        }

        float media_PE = calcular_media(notas_PE, 4);
        float media_AC = calcular_media(notas_AC, 5);
        float media_PP = calcular_media(notas_PP, 10);
        float media_EB = calcular_media(notas_EB, 3);

        candidatos[contador1].nota_final = (media_PE * 0.3) + (media_AC * 0.1) + (media_PP * 0.4) + (media_EB * 0.2);
    }

    qsort(candidatos, num_candidatos, sizeof(Candidato), comparar);

    printf("\nClassificacao dos 15 melhores candidatos:\n");
    for (contador1 = 0; contador1 < num_candidatos && contador1 < 15; contador1++) {
        printf("%d. %s - %.2f\n", contador1 + 1, candidatos[contador1].nome, candidatos[contador1].nota_final);
    }

    return 0;
}
