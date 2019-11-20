#include "operacoes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*
 * criaOperacoes: Cria um valor do tipo Operacoes com os valores dos parâmetros setados em 0
 * retorno: Operacoes
 */
Operacoes criaOperacoes() {
    Operacoes operacoes;
    operacoes.qntdOperacoes = 0;

    return operacoes;
}

/*
 * adicionaOperacao: Adiciona uma nova operacao na lista de operacoes
 * parametro *operacoes: ponteiro para a estrutura que contem as operacoes
 * parametro operacao[]: Novo parâmetro a ser adicionado
 * retorno: Retorna por referência a estrutura de operações com uma nova operação adicionada
 */
void adicionaOperacao(Operacoes *operacoes, char operacao[]){
    if((*operacoes).qntdOperacoes == 0){
        (*operacoes).operacoes = (Operacao*) malloc(1 * sizeof(Operacao));
    } else {
        (*operacoes).operacoes = (Operacao*) realloc((*operacoes).operacoes,((*operacoes).qntdOperacoes + 1) * sizeof(Operacao));
    }

    strcpy((*operacoes).operacoes[(*operacoes).qntdOperacoes].operacao, operacao);
    (*operacoes).qntdOperacoes++;
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

/*
 * adicionaParametro: Acrescenta um novo parâmetro para a operação
 * parametro *operacao: Ponteiro para uma operacao específica
 * parametro novoParametro[]: Novo parâmetro a ser adicionado
 * retorno: Retorna por referência uma operação com um novo parâmetro adicionado
 */
void adicionaParametro(Operacao *operacao, char novoParametro[]){
    if((*operacao).qntdParametros == 0){
        (*operacao).parametros = (char**) malloc(1 * sizeof(char*));
        (*operacao).parametros[0] = (char*) malloc(10 * sizeof(char));
        (*operacao).qntdParametros = 0;
    } else {
        (*operacao).parametros = realloc((*operacao).parametros, ((*operacao).qntdParametros + 1) * sizeof(char*));
        (*operacao).parametros[(*operacao).qntdParametros] = malloc(10 * sizeof(char));
    }

    strcpy((*operacao).parametros[(*operacao).qntdParametros], novoParametro);
    (*operacao).qntdParametros++;
}
