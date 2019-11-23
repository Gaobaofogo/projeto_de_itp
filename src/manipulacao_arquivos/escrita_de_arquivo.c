#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../operacoes/operacoes.h"
#include "../imagem/imagem.h"


/*Operacoes operacoes*/
void desenhaImagem(Operacoes operacoes){
    int k;
    Imagem imagem;
    Pixel cor;
    defineCor(&cor, 0, 0, 0);

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

            imagem = criaImagem(operacoes.operacoes[k].parametros);

        } else if(strcmp("clear", operacoes.operacoes[k].operacao) == 0){
            /* Pega os valores rgb e preenche toda a imagem com a cor desejada */
            int r = atoi(operacoes.operacoes[k].parametros[0]);
            int g = atoi(operacoes.operacoes[k].parametros[1]);
            int b = atoi(operacoes.operacoes[k].parametros[2]);

            clear(&imagem, r, g, b);
        } else if(strcmp("line", operacoes.operacoes[k].operacao) == 0){
            int x0 = atoi(operacoes.operacoes[k].parametros[0]);
            int y0 = atoi(operacoes.operacoes[k].parametros[1]);
            int x1 = atoi(operacoes.operacoes[k].parametros[2]);
            int y1 = atoi(operacoes.operacoes[k].parametros[3]);

            if(x0 == imagem.dimX){
                x0--;
            }

            if(x1 == imagem.dimX){
                x1--;
            }

            if(y0 == imagem.dimY){
                y0--;
            }

            if(y1 == imagem.dimY){
                y1--;
            }

            line(&imagem, cor, x0, y0, x1, y1);

        } else if(strcmp("color", operacoes.operacoes[k].operacao) == 0){
            int r = atoi(operacoes.operacoes[k].parametros[0]);
            int g = atoi(operacoes.operacoes[k].parametros[1]);
            int b = atoi(operacoes.operacoes[k].parametros[2]);

            defineCor(&cor, r, g, b);

        } else if(strcmp("polygon", operacoes.operacoes[k].operacao) == 0){
            /* Pega a quantidade de pontos que o polígono vai ter e cria
               uma matriz para guardar os pontos */
            desenhaPoligono(&imagem, operacoes.operacoes[k].parametros, cor);

        } else if(strcmp("save", operacoes.operacoes[k].operacao) == 0){

            salvarImagem(&imagem, operacoes.operacoes[k].parametros);

        } else if(strcmp("fill", operacoes.operacoes[k].operacao) == 0){
            int x = atoi(operacoes.operacoes[k].parametros[0]);
            int y = atoi(operacoes.operacoes[k].parametros[1]);

            if(x == imagem.dimX){
                x--;
            }

            if(y ==  imagem.dimY){
                y--;
            }

            baldeDeTinta(&imagem, cor, x, y);
        } else if(strcmp("circle", operacoes.operacoes[k].operacao) == 0){
            int x = atoi(operacoes.operacoes[k].parametros[0]);
            int y = atoi(operacoes.operacoes[k].parametros[1]);
            int raio = atoi(operacoes.operacoes[k].parametros[2]);

            desenhaCirculo(&imagem, x, y, raio, cor);
        }
    }

    /* Liberação de memória dos pixels */
    liberarEspacoPixels(&imagem);
}