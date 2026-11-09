#include <stdio.h>
#include <stdlib.h>
#include "maior_subsequencia_comum.h"
#include "str_format.h"

int main(){

    printf("Digite a primeira string: \n");
    char *str_input1 = novaString();

    printf("Digite a segunda string: \n");
    char *str_input2 = novaString();
    
    char * msc = maior_subsequencia_comum(str_input1, str_input2);
    printf("Maior Subsequencia Comum: %s\n", msc);
    return 0;
}