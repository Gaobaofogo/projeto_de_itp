#include <stdio.h>
#include <stdlib.h>
#include "src/manipulacao_arquivos/leitura_de_arquivo.h"
/* #include "src/manipulacao_arquivos/escrita_de_arquivo.h" */


int main(){
  Operacoes operacoes;
  int i, j;

  leituraDeArquivo("teste.txt", &operacoes);

  /*for(i = 0; i < operacoes.qntdOperacoes; i++){
    printf("%s ", operacoes.operacoes[i].operacao);
    for(j = 0; j < operacoes.operacoes[i].qntdParametros; j++){
      printf("%s ", operacoes.operacoes[i].parametros[j]);
    }
  } */

  for(i = 0; i < operacoes.qntdOperacoes; i++){
    for(j = 0; j < operacoes.operacoes[i].qntdParametros; j++){
      free(operacoes.operacoes[i].parametros[j]);
    }

    free(operacoes.operacoes[i].parametros);
  }

  /*
typedef struct{
    char operacao[8];
    char **parametros;
    int qntdParametros;
} Operacao;

typedef struct{
    Operacao *operacoes;
    int qntdOperacoes;
} Operacoes;
*/

  /*desenhaImagem();*/

  return 0;
}
