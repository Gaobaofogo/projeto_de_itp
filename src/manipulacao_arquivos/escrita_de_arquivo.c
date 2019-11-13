#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int r;
    int g;
    int b;
} pixel;

/*seria chamar no parametro uma matriz numa struct(?? kkk) com a
a entrada tambem das duas dimensoes X e Y */
void cor(pixel **matriz, int dimX, int dimY){
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

/*Operacoes operacoes*/
void desenhaImagem(){
    int dimX, dimY;
    int i, j;
    pixel **image;
    FILE *arquivo;

    /*Escrever na matriz de pixels o que deve ser feito

    if(operacao == "image") {
        dimX = operacao.parametro[0];
        dimY = operacao.parametro[1];
    }

    Escrever de fato a imagem*/
    arquivo = fopen("./checkpoint1.ppm", "wb");
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
}
