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

void swapPixel(int dimX, int dimY, int caracter1, int caracter2, int caracter3) {
    int i, j; 
    int imagem[i][j];
    for ( ;i < dimX; ++i){
        for (; j < dimY; ++j){

          if (imagem[i][j]==caracter1){ 
            printf("\u2588 ");
          } else {
            printf("%c ", imagem[i][j]);
          }
        }
        printf("\n");
      }
}

int setPoint(int x, int y, int caracter1,int caracter2, int caracter3) {
    /*imagem[x][y].r = caracter1;
    imagem[x][y].g = caracter2;
    imagem[x][y].b = caracter3;*/
}

int sign(int num) {
    int result;
    if(num < 0) {
        result = -1;
    }
    if(num == 0) {
        result = 0;
    }
    if(num > 0) {
        result = 1;
    }
    return(result);
}

void line_b(int x1, int y1, int x2, int y2) {
    int dx, dy, incrementoE, incrementeNE, d, x, y;

    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    d = 2*dy - dx;
    incrementoE = 2*dy;
    incrementeNE = 2*(dy-dx);

    setPoint(x, y, 0,0,0);
    while(x < x1) {
        if(d<=0) {
            d = d + incrementoE;
            x = x+1;
        }
        else {
            d = d + incrementeNE;
            x = x +1;
            y = y + 1;
        }
    }
    setPoint(x, y, 0,0,0);
}

/* Generalized Bresenham's Algorithm */
void bres_general(Pixel **imagem, int x1, int y1, int x2, int y2){
  
  int dx, dy, x, y, d, s1, s2, swap=0, temp, i;

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  s1 = sign(x2-x1);
  s2 = sign(y2-y1);

  /* Check if dx or dy has a greater range */
  /* if dy has a greater range than dx swap dx and dy */
  if(dy > dx){
    temp = dx; 
    dx = dy; 
    dy = temp; 
    swap = 1;
  }

  /* Set the initial decision parameter and the initial point */
  d = 2 * dy - dx;
  x = x1;
  y = y1;

  for(i = 1; i <= dx; i++) {

    pintaPixel(imagem, x, y, 0, 0, 0);
    
    while(d >= 0) {
      if(swap){
        x = x + s1;
      } else {
        y = y + s2;
        d = d - 2* dx;
      }
    }
    if(swap) y = y + s2;
    else x = x + s1;
    d = d + 2 * dy;
  }
  pintaPixel(imagem, x, y, 0, 0, 0);
}

/*Operacoes operacoes*/
void desenhaImagem(char nome[], Operacoes operacoes){
    int dimX, dimY;
    int i, j, k, w;
    Pixel **image;
    Pixel cor;
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
            int inicioX = atoi(operacoes.operacoes[k].parametros[0]);
            int fimX = atoi(operacoes.operacoes[k].parametros[1]);
            int inicioY = atoi(operacoes.operacoes[k].parametros[2]);
            int fimY = atoi(operacoes.operacoes[k].parametros[3]);

            bres_general(image, inicioX, inicioY, fimX, fimY);

            pintaPixel(image, inicioX, inicioY, cor.r, cor.g, cor.b);
            pintaPixel(image, fimX, fimY, cor.r, cor.g, cor.b);
        } else if(strcmp("color", operacoes.operacoes[k].operacao) == 0){
            int r = atoi(operacoes.operacoes[k].parametros[0]);
            int g = atoi(operacoes.operacoes[k].parametros[1]);
            int b = atoi(operacoes.operacoes[k].parametros[2]);

            defineCor(&cor, r, g, b);
        }
    }

    /* Escrita de arquivo */
    FILE *arquivo;
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
    
    fclose(arquivo);

    /* Liberação de memória dos pixels */
    for(i = 0; i < dimX; i++){
        free(image[i]);
    }
    free(image);
}