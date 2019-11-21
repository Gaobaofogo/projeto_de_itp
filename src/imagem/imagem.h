#ifndef IMAGEM_H
#define IMAGEM_H

typedef struct{
    int r;
    int g;
    int b;
} Pixel;

typedef struct{
    int dimX;
    int dimY;
    Pixel **pixels;
} Imagem;

Imagem criaImagem(char **parametros);
void pintaPixel(Imagem *imagem, int x, int y, int r, int g, int b);
void defineCor(Pixel *cor, int r, int g, int b);
void clear(Imagem *imagem, int r, int b, int g);
void line(Imagem *imagem, Pixel cor, int x0, int y0, int x1, int y1);
void desenhaPoligono(Imagem *imagem, char **parametros, Pixel cor);
void salvarImagem(Imagem *imagem, char **parametros);
void liberarEspacoPixels(Imagem *imagem);
#endif