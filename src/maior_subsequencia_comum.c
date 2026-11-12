#include <stdio.h>
#include <stdlib.h>
#include "str_format.h"
#include "maior_subsequencia_comum.h"

int **cria_matriz_inicial(int nLinhas, int nColunas){
    int **mat = calloc(nLinhas, sizeof(int*));

    if(mat == NULL) exit(1);
    
    for(int i = 0; i < nLinhas; i++){
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

void imprime_matriz(int **mat, int nLinhas, int nColunas){
 
    for(int i = 0; i < nLinhas; i++){
        for(int j = 0; j < nColunas; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int **monta_matriz_prog_dinamica(char *str1, char *str2){
    int nLinhas = tamanhoString(str1) + 1;
    int nColunas = tamanhoString(str2) + 1;
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

int tamanho_maior_subsequencia_comum(int **mat, int coord_linha, int coord_coluna){
    return mat[coord_linha][coord_coluna];
}

char *maior_subsequencia_comum(char *str1, char *str2){
    int **mat = monta_matriz_prog_dinamica(str1, str2);
    int ehIgual = 0;

    int tamStr1 = tamanhoString(str1);
    int tamStr2 =  tamanhoString(str2);
    int tamMaiorSubcomum = tamanho_maior_subsequencia_comum(mat, tamStr1, tamStr2);
    char *maiorSubComum = malloc(sizeof(char) * tamMaiorSubcomum);

    int i = tamStr1;
    int j = tamStr2
    int x = tamMaiorSubcomum - 1;

    while(mat[i][j] && x > -1){
        ehIgual = verifica_letras_iguais(str1[i-1], str2[j-1]);
        if(ehIgual){
            maiorSubComum[x] = str1[i-1];
            x--; 

            //Parte para a diagonal superior esquerda
            i--; 
            j--;
        }
        else{
            //Parte para a posição de maior valor entre cima e lado esquerdo
            if(mat[i-1][j] > mat[i][j-1]) i--;
            else j--; 
        }
    }
    free(mat);
    return maiorSubComum;
}