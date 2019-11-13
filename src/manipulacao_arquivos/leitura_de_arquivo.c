#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../operacoes/operacoes.h"

/*
 * leituraDeOperacoes: Varre o arquivo e devolve uma estrutura com todas as operações de escrita contidas
 * parametro *arquivo: Ponteiro para o arquivo a ser lido
 * retorno: Um struct Operacoes
 */
Operacoes leituraDeOperacoes(FILE *arquivo){
    Operacoes operacoes = criaOperacoes();
    char textoArquivo[50];
    char *valores;
    int contadorOperacao = 0, primeiraOperacao = 1;

    while(fgets(textoArquivo, 50, arquivo) != NULL){
        valores = strtok(textoArquivo, " \n");

        do{
            if(primeiraOperacao){
                adicionaOperacao(&operacoes, valores);
                primeiraOperacao = 0;
            } else{
                adicionaParametro(&operacoes.operacoes[contadorOperacao], valores);
            }

            valores = strtok(NULL, " ");
        }while(valores != NULL);

        contadorOperacao++;
        primeiraOperacao = 1;
    }

    return operacoes;
}

/*
 * leituraDeArquivo: Encapsula 'leituraDeOperacoes' e checa erros na leitura do arquivo
 * parametro nomeArquivo[]: Caminho onde o arquivo será lido
 * parametro: Ponteiro para as operações
 * retorno: Retorno por parâmetro
 *              1 -> Leitura de arquivo deu errado
 *              0 -> Leitura de arquivo com sucesso
 *          Retorno por referência
 *              *operacoes -> Uma struct de Operacoes
 */
int leituraDeArquivo(char nomeArquivo[], Operacoes *operacoes) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if(arquivo == NULL){
        printf("Erro ao ler arquivo\n");
        return 1;
    }

    *operacoes = leituraDeOperacoes(arquivo);

    fclose(arquivo);

    return 0;
}