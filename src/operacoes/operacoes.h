#ifndef OPERACOES_H
#define OPERACOES_H

typedef struct{
    char operacao[10];
    char parametros[7][10];
    int qntdParametros;
} Operacao;

typedef struct{
    Operacao operacoes[15];
    int qntdOperacoes;
} Operacoes;

Operacoes criaOperacoes();
void adicionaOperacao(Operacoes *operacoes, char operacao[]);
void adicionaParametro(Operacao *operacao, char novoParametro[]);
#endif