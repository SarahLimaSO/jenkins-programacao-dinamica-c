#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_format.h"

char *novaString(){
    char temp_buffer[100];

    fgets(temp_buffer, sizeof(temp_buffer), stdin);

    // Remove o '\n' do fgets
    temp_buffer[strcspn(temp_buffer, "\n")] = '\0';

    char *str = malloc(strlen(temp_buffer) + 1);

    if (str == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
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