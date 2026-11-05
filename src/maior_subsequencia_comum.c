#include <stdio.h>
#include <stdlib.h>
#include "maior_subsequencia_comum.h"
#include <string.h>

void imprimeString(char *str);
void contaCaracteres(char *str);
void removeEspaco(char *str);

int main() {
    char temp_buffer[100]; 

    printf("Digite uma string: ");
    fgets(temp_buffer, sizeof(temp_buffer), stdin);

    // Remove o '\n' do fgets
    temp_buffer[strcspn(temp_buffer, "\n")] = '\0';

    // Aloca memória suficiente
    char *str = malloc(strlen(temp_buffer) + 1);

    if (str == NULL) {
        printf("Erro de alocacao!\n");
        return 1;
    }

    strcpy(str, temp_buffer);

    imprimeString(str);
    contaCaracteres(str);

    free(str); // libera memória

    return 0;
}

void imprimeString(char *str) {
    printf("String: %s\n", str);
}

void contaCaracteres(char *str) {
    printf("Tamanho: %zu\n", strlen(str));
}