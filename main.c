#include <stdio.h>
#include "src/manipulacao_arquivos/leitura_de_arquivo.h"


int main(){
  int i;
  Operacoes operacoes;

  leituraDeArquivo("teste.txt", &operacoes);

  for(i = 0; i < 10; i++){
      printf("Operacao %s\n", operacoes.operacoes[i].operacao);
  }

  return 0;
}
