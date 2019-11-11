#include "operacoes.h"
#include <string.h>

/*
 * criaOperacoes: Cria um valor do tipo Operacoes com os valores dos parâmetros setados em 0
 * retorno: Operacoes
 */
Operacoes criaOperacoes() {
    Operacoes operacoes;
    operacoes.qntdOperacoes = 0;

    for(int i = 0; i < 15; i++){
        operacoes.operacoes[i].qntdParametros = 0;        
    }

    return operacoes;
}

/*
 * adicionaOperacao: Adiciona uma nova operacao na lista de operacoes
 * parametro *operacoes: ponteiro para a estrutura que contem as operacoes
 * parametro operacao[]: Novo parâmetro a ser adicionado
 * retorno: Retorna por referência a estrutura de operações com uma nova operação adicionada
 */
void adicionaOperacao(Operacoes *operacoes, char operacao[]){
    strcpy((*operacoes).operacoes[(*operacoes).qntdOperacoes].operacao, operacao);
    (*operacoes).qntdOperacoes++;
}

/*
 * adicionaParametro: Acrescenta um novo parâmetro para a operação
 * parametro *operacao: Ponteiro para uma operacao específica
 * parametro novoParametro[]: Novo parâmetro a ser adicionado
 * retorno: Retorna por referência uma operação com um novo parâmetro adicionado
 */
void adicionaParametro(Operacao *operacao, char novoParametro[]){
    strcpy((*operacao).parametros[(*operacao).qntdParametros], novoParametro);
    (*operacao).qntdParametros++;
}
