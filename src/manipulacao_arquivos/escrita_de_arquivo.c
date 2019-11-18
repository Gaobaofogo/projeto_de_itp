#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../operacoes/operacoes.h"

typedef struct{
    int r;
    int g;
    int b;
} Pixel;

/*seria chamar no parametro uma matriz numa struct(?? kkk) com a
a entrada tambem das duas dimensoes X e Y */
void cor(Pixel **matriz, int dimX, int dimY){
    int i, j;

    for (i = 0; i < dimX; i++){
        for (j = 0; j < dimY; j++){
        /*a 'formula' de um intervalo de random: a+(rand())%(b-a)
        no nosso caso, a = 0 e b = 255 */
            matriz[i][j].r = 0+(rand())%255;
            matriz[i][j].g = 0+(rand())%255;
            matriz[i][j].b = 0+(rand())%255;
        }
    }
}

void clear(Pixel **image, int largura, int altura, int r, int b, int g){
    int i, j;

    for(i = 0; i < largura; i++){
        for(j = 0; j < altura; j++){
            image[i][j].r = r;
            image[i][j].g = g;
            image[i][j].b = b;
        }
    }
}

/*Operacoes operacoes*/
void desenhaImagem(char nome[], Operacoes operacoes){
    int dimX, dimY;
    int i, j, k, w;
    Pixel **image;

    for(k = 0; k < operacoes.qntdOperacoes; k++){
        if(strcmp("image", operacoes.operacoes[k].operacao) == 0){
            dimX = atoi(operacoes.operacoes[k].parametros[0]);
            dimY = atoi(operacoes.operacoes[k].parametros[1]);

            image = (Pixel **) malloc(dimX * sizeof(Pixel));

            for(j = 0; j < dimY; j++){
                image[j] = (Pixel *) malloc(dimY * sizeof(Pixel));
            }
        } else if(strcmp("clear", operacoes.operacoes[k].operacao) == 0){
            int r = atoi(operacoes.operacoes[k].parametros[0]);
            int g = atoi(operacoes.operacoes[k].parametros[1]);
            int b = atoi(operacoes.operacoes[k].parametros[2]);
            clear(image, dimX, dimY, r, g, b);
        }
    }

    for(i = 0; i < dimX; i++){
        free(image[i]);
    }

    free(image);

    /*FILE *arquivo;

    arquivo = fopen(nome, "wb");
    fprintf(arquivo, "P3 \n");
    fprintf(arquivo, "%d %d \n", dimX, dimY);
    fprintf(arquivo, "255 \n");
    
    for (i = 0; i < dimX; i++){
        for (j = 0; j < dimY; j++){
            fprintf(arquivo, "%i ", image[i][j].r);
            fprintf(arquivo, "%i ", image[i][j].g);
            fprintf(arquivo, "%i \n", image[i][j].b);
        }
    }
    
    fclose(arquivo); */
}
