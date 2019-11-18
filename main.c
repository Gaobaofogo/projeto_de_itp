#include <stdio.h>
#include <stdlib.h>
#include "src/manipulacao_arquivos/leitura_de_arquivo.h"
#include "src/manipulacao_arquivos/escrita_de_arquivo.h"


int main(){
  Operacoes operacoes;
  int i, j;

  leituraDeArquivo("teste.txt", &operacoes);

  desenhaImagem("arquivo.ppm", operacoes);

  for(i = 0; i < operacoes.qntdOperacoes; i++){
    for(j = 0; j < operacoes.operacoes[i].qntdParametros; j++){
      free(operacoes.operacoes[i].parametros[j]);
    }

    free(operacoes.operacoes[i].parametros);
  }

  return 0;
}
