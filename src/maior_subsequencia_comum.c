#include <stdio.h>
#include <stdlib.h>
#include "str_format.h"
#include "maior_subsequencia_comum.h"

int **cria_matriz_inicial(int nLinhas, int nColunas){
    int **mat;

    mat = calloc(nLinhas, sizeof(int*));
    
    for(int i = 0; i < nColunas; i++){
        mat[i] = calloc(nColunas, sizeof(int));
    }
    return mat;
}

int verifica_letras_iguais(char letra_str1, char letra_str2){
    if(letra_str1 == letra_str2) return 1;
    return 0;
}

int max(int valor1, int valor2){
    if(valor1 > valor2) return valor1;
    else return valor2;
}

int **monta_matriz_prog_dinamica(char *str1, char *str2){
    int nLinhas = tamanhoString(str2) + 1;
    int nColunas = tamanhoString(str1) + 1;
    int ehIgual, valor_posicao_diagonal, valor = 0;

    int **mat = cria_matriz_inicial(nLinhas, nColunas);

    for(int i = 1; i < nLinhas; i++){
        for(int j = 1; j < nColunas; j++){

            ehIgual = verifica_letras_iguais(str1[i-1], str2[j-1]);
            valor_posicao_diagonal = mat[i-1][j-1];
            
            if(ehIgual) valor = valor_posicao_diagonal + 1;
            else{
                valor = max(mat[i-1][j], mat[i][j-1]);
            }
            mat[i][j] = valor;
        }
    }    
    return mat;
}
