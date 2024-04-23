#include <stdio.h>
#include <stdlib.h>

#define tam 2532
int matriz[tam][tam];

void verticesMultiplosDeCinco(int n) {
    FILE *arquivo = fopen("dados_grafo_gerador.txt", "w");
    for (int i = 0; i < n; i++) {
        if (i % 5 == 0) { 
            fprintf(arquivo, "%d\n", i); 
        }
    }
    fclose(arquivo);
}

int main(){
    int linha;
    verticesMultiplosDeCinco(linha);
    return 0;
}
