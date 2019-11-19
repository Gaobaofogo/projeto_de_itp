//else if(strcmp("circle", operacoes.operacoes[k].operacao) == 0){

void circle(int rad, int xc, int yc){
	//definimos o Xinicial e Yinicial no ponto maior (= raio) no eixo de Y (x=0); as coordenadas (0, r) para explicar melhor
	int xi= 0;
	int yi = rad;
	//condição inicial de partida
	float d = 5/4 - rad;
	setPointCircle(x, y, cor);
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
		setPointCircle(x, y, cor);
	}





}