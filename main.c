#include <stdio.h>
#include "src/manipulacao_arquivos/leitura_de_arquivo.h"
#include "src/manipulacao_arquivos/escrita_de_arquivo.h"


int main(){
  Operacoes operacoes;

  leituraDeArquivo("teste.txt", &operacoes);

  desenhaImagem();

  return 0;
}
