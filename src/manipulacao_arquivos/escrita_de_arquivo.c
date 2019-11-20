#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../operacoes/operacoes.h"

typedef struct{
    int r;
    int g;
    int b;
} Pixel;

/*
 * defineCor: Pinta um pixel
 * parametro *pixel: Ponteiro para um pixel
 * parametro r: Valor r do formato RGB
 * parametro g: Valor g do formato RGB
 * parametro b: Valor b do formato RGB
 * retorno: Devolve por referência o pixel pintado com a nova cor
 */
void pintaPixel(Pixel **imagem, int x, int y, int r, int g, int b){
    imagem[x][y].r = r;
    imagem[x][y].g = g;
    imagem[x][y].b = b;
}

void defineCor(Pixel *cor, int r, int g, int b){
    (*cor).r = r;
    (*cor).g = g;
    (*cor).b = b;
}
/*
 * clear: Preenche toda a imagem com uma cor especificada em rgb
 * parametro **image: Matriz de pixels que representa a imagem a ser gerada
 * parametro largura: largura da imagem
 * parametro altura: altura da imagem
 * parametro r: Valor r do formato RGB
 * parametro g: Valor g do formato RGB
 * parametro b: Valor b do formato RGB
 * retorno: Devolve por referência a matriz de pixels pintada com a nova cor especificada
 */
void clear(Pixel **image, int largura, int altura, int r, int b, int g){
    int i, j;

    /* Seta todas os pixels com a cor rgb especificada */
    for(i = 0; i < largura; i++){
        for(j = 0; j < altura; j++){
            image[i][j].r = r;
            image[i][j].g = g;
            image[i][j].b = b;
        }
    }
}

void line(Pixel **matrix, Pixel cor, int x0, int y0, int x1, int y1) {
    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
    int err = (dx>dy ? dx : -dy)/2, e2;
    
    for(;;){
        pintaPixel(matrix, x0, y0, cor.r, cor.g, cor.b);

        if (x0==x1 && y0==y1) break;
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

/*Operacoes operacoes*/
void desenhaImagem(char nome[], Operacoes operacoes){
    FILE *arquivo;
    int dimX, dimY;
    int i, j, k;
    Pixel **image;
    Pixel cor;
    cor.r = 0;
    cor.g = 0;
    cor.b = 0;
    /*defineCor(&cor, 0, 0, 0, 0, 0);*/


    /* 
    Este bloco irá percorrer todas as operações lidas no arquivo e vai tomar
    a ação descrita na operação
    */
    for(k = 0; k < operacoes.qntdOperacoes; k++){
        /* Uma sequência de if/else para decidir qual é a operação que o for está varrendo no momento */
        if(strcmp("image", operacoes.operacoes[k].operacao) == 0){
            /*
            Atribui as dimensões da imagem para dimX e dimY e aloca o espaço necessário para a imagem
            como uma matriz de pixels
            */
            dimX = atoi(operacoes.operacoes[k].parametros[0]);
            dimY = atoi(operacoes.operacoes[k].parametros[1]);

            image = (Pixel **) malloc(dimX * sizeof(Pixel *));

            for(j = 0; j < dimX; j++){
                image[j] = (Pixel *) malloc(dimY * sizeof(Pixel));
            }
        } else if(strcmp("clear", operacoes.operacoes[k].operacao) == 0){
            /* Pega os valores rgb e preenche toda a imagem com a cor desejada */
            int r = atoi(operacoes.operacoes[k].parametros[0]);
            int g = atoi(operacoes.operacoes[k].parametros[1]);
            int b = atoi(operacoes.operacoes[k].parametros[2]);

            clear(image, dimX, dimY, r, g, b);
        } else if(strcmp("line", operacoes.operacoes[k].operacao) == 0){
            int x0 = atoi(operacoes.operacoes[k].parametros[0]);
            int y0 = atoi(operacoes.operacoes[k].parametros[1]);
            int x1 = atoi(operacoes.operacoes[k].parametros[2]);
            int y1 = atoi(operacoes.operacoes[k].parametros[3]);

            if(x0 == dimX){
                x0--;
            }

            if(x1 == dimX){
                x1--;
            }

            if(y0 == dimY){
                y0--;
            }

            if(y1 == dimY){
                y1--;
            }

            line(image, cor, x0, y0, x1, y1);
        } else if(strcmp("color", operacoes.operacoes[k].operacao) == 0){
            int r = atoi(operacoes.operacoes[k].parametros[0]);
            int g = atoi(operacoes.operacoes[k].parametros[1]);
            int b = atoi(operacoes.operacoes[k].parametros[2]);

            defineCor(&cor, r, g, b);
        }
    }

    /* Escrita de arquivo */
    arquivo = fopen(nome, "wb");

    fprintf(arquivo, "P3 \n");
    fprintf(arquivo, "%d %d \n", dimX, dimY); fprintf(arquivo, "255 \n"); 
       for (i = 0; i < dimX; i++){
        for (j = 0; j < dimY; j++){
            fprintf(arquivo, "%i ", image[i][j].r);
            fprintf(arquivo, "%i ", image[i][j].g);
            fprintf(arquivo, "%i \n", image[i][j].b);
        }
    }
    
    fclose(arquivo);

    /* Liberação de memória dos pixels */
    for(i = 0; i < dimX; i++){
        free(image[i]);
    }
    free(image);
}