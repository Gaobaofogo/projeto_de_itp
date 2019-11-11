#ifndef ESCRITA_DE_ARQUIVO_H
#define ESCRITA_DE_ARQUIVO_H

typedef struct{
	int r;
	int g;
	int b;	
} Pixel;

// typedef struct{
// 	int largura;
// 	int altura;
// 	Pixel imagem[altura][largura];
// } Imagem;

Pixel criaPixel(int r, int g, int b);
//Imagem criaImagem(int largura, int altura);
void pintaPixel(Pixel *pixel, int r, int g, int b);

#endif