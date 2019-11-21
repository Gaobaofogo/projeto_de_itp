#include <stdio.h>
#include <math.h>

// Center of the cicle = (15, 15)
int xc = pontoX, yc = pontoY;
char imagem[dimX][dimY];

// Plot eight points using circle's symmetrical property
void setPointCircle(Imagem *imagem, int xc, int yc, int x, int y)
{
  ///////////// Era assim no código original

 /*pintaPixel(xc+x, yc+y);
  pintaPixel(xc+x, yc-y);
  pintaPixel(xc+y, yc+x);
  pintaPixel(xc+y, yc-x);
  pintaPixel(xc-x, yc-y);
  pintaPixel(xc-y, yc-x);
  pintaPixel(xc-x, yc+y);
  pintaPixel(xc-y, yc+x);*/

  ///e creio que fique assim após adicionar a parte dos pixels

 //pintaPixel(Imagem *imagem, int x, int y, int r, int g, int b)
  pintaPixel(imagem, xc+x, yc+y, cor.r, cor.g, cor.b);
  pintaPixel(imagem, xc+x, yc-y, cor.r, cor.g, cor.b);
  pintaPixel(imagem, xc+y, yc+x, cor.r, cor.g, cor.b);
  pintaPixel(imagem, xc+y, yc-x, cor.r, cor.g, cor.b);
  pintaPixel(imagem, xc-x, yc-y, cor.r, cor.g, cor.b);
  pintaPixel(imagem, xc-y, yc-x, cor.r, cor.g, cor.b);
  pintaPixel(imagem, xc-x, yc+y, cor.r, cor.g, cor.b);
  pintaPixel(imagem, xc-y, yc+x, cor.r, cor.g, cor.b);

}

void circle(Imagem *imagem, int xc, int yc, int rad){
  //definimos o Xinicial e Yinicial no ponto maior (= raio) no eixo de Y (x=0); as coordenadas (0, r) para explicar melhor
  int x= 0;
  int y=rad;
  //condição inicial de partida
  float d = 5/4 - rad;
  setPointCircle(imagem, xc, yc, x, y, cor);
  while(y > x)
  {
    if (d<0) {
      d = d + 2*x + 3;
      x++;
    } else {
      d = d + 2*(x-y) + 5;
      x++;
      y--;
    }
    setPointCircle(imagem, xc, yc, x, y, cor);
  }
}

/////parte que entraria no + escrita_de_arquivo.c +////////////////////////////////////////
  else if(strcmp("circle", operacoes.operacoes[k].operacao) == 0){
            int xc = atoi(operacoes.operacoes[k].parametros[0]);
            int yc = atoi(operacoes.operacoes[k].parametros[1]);
            int rad = atoi(operacoes.operacoes[k].parametros[2]);