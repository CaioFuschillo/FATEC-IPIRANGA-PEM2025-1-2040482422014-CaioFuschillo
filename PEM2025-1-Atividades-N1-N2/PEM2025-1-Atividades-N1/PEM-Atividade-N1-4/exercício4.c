/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Mostrar diretórios e recursi-    *
* vidade                                                 *
* Data - 27/03/2025                                      * 
* Autor: Caio Fuschillo                                  *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void listar_diretorios(const char *caminho, int nivel);

int main() {
    const char *diretorio_inicial = "."; // "." representa o diretório atual
    listar_diretorios(diretorio_inicial, 0);
    return 0;
}

void listar_diretorios(const char *caminho, int nivel) {
    DIR *dir = opendir(caminho);
    struct dirent *entrada;

    if (dir == NULL) {
        printf("Erro ao abrir o diretorio: %s\n", caminho);
        return;
    }

    // Percorre todas as entradas do diretório
    while ((entrada = readdir(dir)) != NULL) {
        // Ignora as entradas "." e ".."
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0) {
            continue;
        }

        // Cria o caminho completo para o arquivo ou diretório
        char caminho_completo[1024];
        snprintf(caminho_completo, sizeof(caminho_completo), "%s/%s", caminho, entrada->d_name);

        // Imprime o nome com recuo baseado no nível da profundidade
        for (int i = 0; i < nivel; i++) {
            printf("    "); // Recuo para representar o nível
        }
        printf("%s\n", entrada->d_name);

        // Se for um diretório, chama recursivamente
        if (entrada->d_type == DT_DIR) {
            listar_diretorios(caminho_completo, nivel + 1);
        }
    }

    closedir(dir);
}
