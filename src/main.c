#include <stdio.h>
#include <stdlib.h>
#include "maior_subsequencia_comum.h"
#include "str_format.h"

int main(){

    printf("Digite a primeira string: \n");
    char *str_input1 = novaString();

    printf("Digite a segunda string: \n");
    char *str_input2 = novaString();
    
    int ** mat = monta_matriz_prog_dinamica(str_input1, str_input2);
    int tamStr1 = tamanhoString(str_input1);
    int tamStr2 = tamanhoString(str_input1);
    imprime_matriz(mat, tamStr1+1, tamStr2+1);

    int tam_matriz = tamanho_maior_subsequencia_comum(mat, tamStr1, tamStr2);
    printf("tamanho maior msc: %d\n", tam_matriz);

    char * msc = maior_subsequencia_comum(str_input1, str_input2);
    printf("Maior Subsequencia Comum: %s\n", msc);
    return 0;
}