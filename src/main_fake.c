#include <stdio.h>
#include "operacoes.h"
#include "leitura_de_arquivo.h"


int main() {

    Operacoes operacoes;
    int resultado = leituraDeArquivo("teste.txt", &operacoes);

    if(resultado == 1){
        printf("Deu errado\n");
    } else {
        printf("Deu certo\n");
    }

    for(int i = 0; i < 11; i++){
        printf("A operacao eh %s ", operacoes.operacoes[i].operacao);
        printf("com parametros ");

        for(int j = 0; j < operacoes.operacoes[i].qntdParametros; j++){
            printf("%s ", operacoes.operacoes[i].parametros[j]);
        }

        printf("\n");
    }

    return 0;
}
