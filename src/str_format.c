#include <stdio.h>
#include <string.h>
#include "str_format.h"

char *novaString(char *str){
    char temp_buffer[100];

    printf("Digite a string: ");
    fgets(temp_buffer, sizeof(temp_buffer), stdin);

    // Remove o '\n' do fgets
    temp_buffer[strcspn(temp_buffer, "\n")] = '\0';

    str = malloc(strlen(temp_buffer) + 1);

    if (str == NULL) {
        printf("Erro de alocacao!\n");
        return 1;
    }

    strcpy(str, temp_buffer);
    return str;
}
void imprimeString(char *str){
    printf("%s\n", str);
}

void tamanhoString(char *str){
    printf("%zu\n", strlen(str));
}