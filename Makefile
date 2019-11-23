#### Comandos para utilizar #####

# Comando para compilar e linkar todos os arquivos do projeto
# Exemplo de uso: make compila
compila: prog

# Apaga todos os arquivos '.o' que são gerados no processo de compilação e o executável 'prog'
# Exemplo de uso: make remove_lixo
remove_lixo:
	find . -type f -name '*.o' -delete
	rm prog

#### Fim Comandos para utilizar #####


#### Funções auxiliares ####
# Gera um executável do programa chamado 'prog'
prog: src/operacoes/operacoes.o src/fila/fila.o src/imagem/imagem.o src/manipulacao_arquivos/leitura_de_arquivo.o src/manipulacao_arquivos/escrita_de_arquivo.o main.o
	gcc -o prog src/operacoes/operacoes.o src/fila/fila.o src/manipulacao_arquivos/leitura_de_arquivo.o src/manipulacao_arquivos/escrita_de_arquivo.o src/imagem/imagem.o main.o -W -Wall -ansi -pedantic -std=c99

src/fila/fila.o: src/fila/fila.c
	gcc src/fila/fila.c -o src/fila/fila.o -c -W -Wall -ansi -pedantic -std=c99

# Gera o arquivo '.o' de imagem.c
src/imagem/imagem.o: src/imagem/imagem.c
	gcc src/imagem/imagem.c -o src/imagem/imagem.o -c -W -Wall -ansi -pedantic -std=c99

# Gera o arquivo '.o' de operacoes.c
src/operacoes/operacoes.o: src/operacoes/operacoes.c
	gcc src/operacoes/operacoes.c -o src/operacoes/operacoes.o -c -W -Wall -ansi -pedantic -std=c99

# Gera o arquivo '.o' de leitura_de_arquivo.c
src/manipulacao_arquivos/leitura_de_arquivo.o: src/manipulacao_arquivos/leitura_de_arquivo.c
	gcc src/manipulacao_arquivos/leitura_de_arquivo.c -o src/manipulacao_arquivos/leitura_de_arquivo.o -c -W -Wall -ansi -pedantic -std=c99

src/manipulacao_arquivos/escrita_de_arquivo.o: src/manipulacao_arquivos/escrita_de_arquivo.c
	gcc src/manipulacao_arquivos/escrita_de_arquivo.c -o src/manipulacao_arquivos/escrita_de_arquivo.o -c -W -Wall -ansi -pedantic -std=c99

# Gera o arquivo '.o' de main.c
main.o: main.c
	gcc main.c -o main.o  -c -W -Wall -ansi -pedantic -std=c99

#### Fim Funções auxiliares ####