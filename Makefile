compila: prog

prog: operacoes.o leitura_de_arquivo.o operacoes.o main.o
	gcc -o prog leitura_de_arquivo.o operacoes.o