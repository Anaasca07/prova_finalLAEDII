#include <stdio.h>
#include <stdlib.h>

#define tam 2532
int matriz[tam][tam];

void verIsolado(){
    int i, j;
    int eIsolado;

    for(i = 0; i < tam; i++) {
        eIsolado = 1;
        for(j = 0; j < tam; j++) {
            if(matriz[i][j] != 0) {
                eIsolado = 0;
                break;
            }
        }
        if(eIsolado) {
            printf("O vertice %d e isolado.\n", i);
            return;
        }
    }
    printf("Nao existe vertices isolado nesse grafo\n");
}

int main(){
    verIsolado();
    return 0;
}