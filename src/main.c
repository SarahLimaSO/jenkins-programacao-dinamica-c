#include <stdio.h>
#include <stdlib.h>
#include "maior_subsequencia_comum.h"
#include "str_format.h"

int main(){
    char *str_input1;
    char *str_input2;
    char * msc;
    
    str_input1 = novaString();
    str_input2 = novaString();

    imprimeString(str_input1);
    imprimeString(str_input2);
    return 0;
}