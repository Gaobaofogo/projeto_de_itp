#include<stdio.h>
#include<stdlib.h>

char image[dimX][dimY];

void swapPixel(int dimX, int dimY, char caracter) {
	for (int i = 0; i < linhas; ++i){
	    for (int j = 0; j < colunas; ++j){
	      if (desenho[i][j]==caracter){ 
	        printf("\u2588 ");
	      } else {
	        printf("%c ", desenho[i][j]);
	      }
	    }
	    printf("\n");
	  }
}
int setPoint(int x, int y, char caracter) {
	image[y][x] = caracter;
	//a cada laço do for vai substituir um
	//caracter onde seria os pixels da linha
	//para quando rodar na main, onde tiver esse caracter
	//substituir pelo pixel colorido desejado
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
	d = 2*(dy-dx);
	for(i = 0; i <= dx; i++) {
		/*função de pintar pixel, clear(?)*/
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
//////////////////////////////////MAIN SÓ PRA ORGANIZACAO DA LINHA LÓGICA DO PROGRAMA
void main() {
	//valores fakes que devem ser retirados das dimensoes obtidas no arquivo.txt
	dimX = 500;
	dimY = 600;

	line(100,400,100,500);

	swapPixel(500, 600, '#');

/*Bom, pela lógica que entendi, primeiramente, criamos uma função simples de implementação de um único ponto (x,y)
por um caracter qualquer. Essa função servirá, para quando, percorremos a função responsável pela formação da linha,
a medida que formos passando pelos pontos da linha, seja substituída por esse tal caracter; isso auxiliará na última
função, que, quando varrido toda a matriz de pixels, onde estiver o caracter escolhido iremos substituir pelo pixel
colorido (no caso, formando a linha). Para esse objetivo, ao invés de fazer um for dentro da main, o que é abominável
a essa altura, criei uma função swapPixel (troca de pixel ao pé da letra) - espero só ter acertado na passagem dos
parametros-.

A função sign nada mais é que uma função de retorno inteiro -1, 0 ou 1 para cada respectivo valor de X negativo, zero
ou positivo. Isso auxiliará na hora da função principal linha;

Na função do line, podemos entender melhor lendo o arquivo do pdf do projeto mesmo, caso não entendam 100% o que eu
vou escrever (ou pelo menos tentar kkk).
- primeiro: obtemos os valores (absolutos) de dx e dy, que é a diferença dos x e y finais pelos seus x e y iniciais; e
o sign 1 e 2 para o retorno -1, 0 ou 1 das diferenças dx e dy;
- segundo: se a diferença de dy for mais que dx, fazemos a troca desses valores utilizando um auxiliar 'temp' (pq temp
o nome? boníssima pergunta!);
- antes de abrir o laço for, definimos o parametro de decisão inicial como sendo o dobro das diferenças dy e dx; e o
x e y como sendo os primeiros pontos x1 e y2 que foram recebidos como entrada na função da linha;
- abrindo o for, a cada laço através da função setPoint já é escolhida o caracter que formará a linha na matriz até aqui;
- se houve a troca de de dy com dx, e então nosso swap é 1; se swap for 1 as condições são iniciadas: **mais atenção**
~> então, ENQUANTO o d for maior ou igual a zero, se o swap for 1, somamos o x mais o sign de dx (-1, 0 ou 1) ao valor de
x a cada laço, caso swap não seja 1, ele faz o mesmo com y a cada repetição; no final diminuindo ao parametro de decisao
o valor do parametro - dobro de dx;
~> e se, d for menor que zero, se o swap for 1, somamos o y mais seus sign de dy (-1, 0 ou 1) ao valor de y a cada repetição
e caso contrário, swap diferente de 1, faz-se com x; somendo ao parametro de decisao seu valor mais o dobro de dy;







}