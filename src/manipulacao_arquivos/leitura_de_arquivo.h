#ifndef LEITURA_DE_ARQUIVO_H
#define LEITURA_DE_ARQUIVO_H

#include "../operacoes/operacoes.h"
#include <stdio.h>

Operacoes leituraDeOperacoes(FILE *arquivo);
int leituraDeArquivo(char nomeArquivo[], Operacoes *operacoes);

#endif