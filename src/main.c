#include <stdio.h>
#include "maior_subsequencia_comum.h"
#include "str_format.h"

int main(){

    printf("Digite a primeira string: \n");
    char *str_input1 = novaString();

    printf("Digite a segunda string: \n");
    char *str_input2 = novaString();

    int nlin = tamanhoString(str_input1);
    int ncol = tamanhoString(str_input2);

    int** mat = monta_matriz_prog_dinamica(str_input1, str_input2);
    int tamMaiorSub = tamanho_maior_subsequencia_comum(mat, nlin, ncol);
    printf("Tamanho Maior Subsequencia Comum: %d\n", tamMaiorSub);
    
    char * msc = maior_subsequencia_comum(str_input1, str_input2);
    printf("Maior Subsequencia Comum: %s\n", msc);

    return 0;
}