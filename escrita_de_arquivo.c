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

    for (int i = 0; i < dimX; i++){
            for (int j = 0; j < dimY; j++){
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
    int dimX, dimY, i;
    pixel **image;

    /*Escrever na matriz de pixels o que deve ser feito

    if(operacao == "image") {
        dimX = operacao.parametro[0];
        dimY = operacao.parametro[1];
    }

    Escrever de fato a imagem*/
    arquivo = fopen("./checkpoint1.ppm", "w+");
    fprintf(fp, "P3 \n");
    fprintf(fp, "%d %d \n", dimX, dimY);
    fprintf(fp, "255 \n");
    
    for (i = 0; i < dimX; i++){
        for (int j = 0; j < dimY; j++){
            fprintf(fp, "%i ", image[i][j].r);
            fprintf(fp, "%i ", image[i][j].g);
            fprintf(fp, "%i \n", image[i][j].b);
        }
    }
    
    fclose(arquivo);
}
