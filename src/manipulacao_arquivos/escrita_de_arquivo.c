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

/*Operacoes operacoes*/
void desenhaImagem(char nome[], Operacoes operacoes){
    int dimX, dimY;
    int i, j, k, w;
    Pixel **image;

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

            image = (Pixel **) malloc(dimX * sizeof(Pixel));

            for(j = 0; j < dimY; j++){
                image[j] = (Pixel *) malloc(dimY * sizeof(Pixel));
            }
        } else if(strcmp("clear", operacoes.operacoes[k].operacao) == 0){
            /* Pega os valores rgb e preenche toda a imagem com a cor desejada */
            int r = atoi(operacoes.operacoes[k].parametros[0]);
            int g = atoi(operacoes.operacoes[k].parametros[1]);
            int b = atoi(operacoes.operacoes[k].parametros[2]);
            clear(image, dimX, dimY, r, g, b);
        } else if(strcmp("line", operacoes.operacoes[k].operacao) == 0) {
           
            /* Código para inserir linha deve estar aqui*/
            
            
            
            void swapPixel(int dimX, int dimY, char caracter) {
                int i, j; 
                for ( ;i < dimX; ++i){
                    for (; j < dimY; ++j){

                      if (imagem[i][j]==caracter){ 
                        printf("\u2588 ");
                      } else {
                        printf("%c ", imagem[i][j]);
                      }
                    }
                    printf("\n");
                  }
            }
            int setPoint(int x, int y, char caracter) {
                image[y][x] = caracter;
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
            void line(int xi,int yi,int xf,int yf) {
                
                int d, dx, dy, temp, x, y, i, s1, s2, swap;

                x = xi;
                y = yi;
                dx = abs(xf - xi);
                dy = abs(yf - yi);
                s1 = sign(xf - xi);
                s2 = sign(yf - yf);

                swap = 0;
                if(dy>dx) {
                    temp = dx;
                    dx = dy;
                    dy = temp;
                    swap = 1;
                }
                else {
                    swap = 0;
                }
                d = 2*dy-dx;
                for(i = 0; i <= dx; i++) {
                    setPoint(x, y, '#');
                    if(d >= 0) {
                        if(swap == 1) {
                            x = x+s1;
                        }
                        else {
                            y = y+s2;
                        }
                        d = d-(2*dx);
                    }
                    if(swap ==1) {
                        y = y+s2;
                    }
                    else {
                        x = x+s1;
                    }
                    d = d+(2*dy);
                }
                setPoint(x, y, '#');
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

                setPoint(x, y, '#');
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
                setPoint(x, y, '#');
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
}
