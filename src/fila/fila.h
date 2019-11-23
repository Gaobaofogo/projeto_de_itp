#ifndef FILA_H
#define FILA_H

typedef struct{
    int posicaoCartesiana[2];
} Dados;

typedef struct Noh_t{
    Dados dados;
    struct Noh_t *ramo;
} Noh;

typedef struct{
    int tamanho;
    Noh *cabeca;
    Noh *calda;
} Fila;

Fila criaFila();
void adicionaElemento(Fila *fila, int x, int y);
Noh *retiraElemento(Fila *fila);
void liberaMemoriaFila(Fila *fila);
int estahVazio(Fila *fila);
#endif