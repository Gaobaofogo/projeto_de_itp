#include <stdio.h>
#include "operacoes.h"
#include "leitura_de_arquivo.h"
#include "escrita_de_arquivo.h"



int main() {

    Pixel imagem[3][2];
    FILE *arquivo = fopen("teste.ppm", "w+");
    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "3 2\n");
    fprintf(arquivo, "255\n");

    pintaPixel(&imagem[0][0], 255, 0,   0);
    pintaPixel(&imagem[0][1], 0,   255, 0);
    pintaPixel(&imagem[1][0], 0,   0,   0);
    pintaPixel(&imagem[1][1], 255, 255, 0);
    pintaPixel(&imagem[2][0], 255, 255, 255);
    pintaPixel(&imagem[2][1], 0,   0,   0);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            fprintf(arquivo, "%i %i %i\n", imagem[i][j].r, imagem[i][j].g, imagem[i][j].b);
        }
    }

    fclose(arquivo);

    return 0;
}
