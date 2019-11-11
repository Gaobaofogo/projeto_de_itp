/*
Função que escreva em arquivo
OUtra função que receba parâmetros e diga como vai ser aquele determinado pixel
*/

#include "escrita_de_arquivo.h"


Pixel criaPixel(int r, int g, int b){
	Pixel pixel;

	pixel.r = r;
	pixel.g = g;
	pixel.b = b;

	return pixel;
}

Pixel criaImagem(int largura, int altura){
	Pixel imagem[largura][altura];

	return // alguma coisa que referencia imagem;
}

void pintaPixel(Pixel *pixel, int r, int g, int b){
	(*pixel).r = r;
	(*pixel).g = g;
	(*pixel).b = b;
}