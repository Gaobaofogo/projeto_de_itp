#ifndef OPERACOES_H
#define OPERACOES_H

typedef struct{
    char *operacao;
    char **parametros;
    int qntdParametros;
} Operacao;

typedef struct{
    Operacao *operacoes;
    int qntdOperacoes;
} Operacoes;

Operacoes criaOperacoes();
void adicionaOperacao(Operacoes *operacoes, char operacao[]);
void adicionaParametro(Operacao *operacao, char novoParametro[]);
#endif