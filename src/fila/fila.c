#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

Fila criaFila(){
    Fila novaFila;

    novaFila.tamanho = 0;

    return novaFila;
}

void adicionaElemento(Fila *fila, int x, int y){
    if((*fila).tamanho == 0){
        Dados novoDado;
        novoDado.posicaoCartesiana[0] = x;
        novoDado.posicaoCartesiana[1] = y;

        Noh *novoNoh = (Noh*) malloc(1 * sizeof(Noh));
        (*novoNoh).dados = novoDado;

        (*fila).cabeca = (Noh*) malloc(1 * sizeof(Noh));
        (*fila).calda = (Noh*) malloc(1 * sizeof(Noh));

        (*fila).cabeca = novoNoh;
        (*fila).calda = novoNoh;
    } else {
        Dados novoDado;
        novoDado.posicaoCartesiana[0] = x;
        novoDado.posicaoCartesiana[1] = y;

        Noh *novoNoh = malloc(1 * sizeof(Noh));
        (*novoNoh).dados = novoDado;

        (*fila).calda->ramo = novoNoh;
        (*fila).calda = novoNoh;
    }

    (*fila).tamanho++;
}

Noh *retiraElemento(Fila *fila){
    if(fila->tamanho == 0){
        printf("Tamanho da fila eh zero\n");
    }

    Noh *item = (*fila).cabeca;
    (*fila).cabeca = (*fila).cabeca->ramo;
    (*fila).tamanho--;
    return item;
}

void liberaMemoriaFila(Fila *fila){
    Noh *noh;
    while(!estahVazio(fila)){
        noh = retiraElemento(fila);
        free(noh);
    }
}

int estahVazio(Fila *fila){
    if(fila->tamanho == 0){
        return 1;
    } else {
        return 0;
    }
}