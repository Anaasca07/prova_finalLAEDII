#include <stdio.h>
#include <stdlib.h>

#define tam 2532
int matriz[tam][tam];

int gVertice(int vertice, int n) {
    int i, grauVert = 0;
    for (i = 0; i < n; i++) {
        if (matriz[vertice][i]) {
            grauVert++;
        }
    }
    return grauVert;
}

void gravarGrausVertices(int n) {
    int i;
    FILE *arquivo = fopen("dados_grafos_graus.txt","w");
    for(i=0; i<n; i++){
        int grauVert = gVertice(i,n);
        fprintf(arquivo, "%d %d\n", i, grauVert);
    }
    fclose(arquivo);
}

int main(){
    int linha;
    gravarGrausVertices(linha);
    return 0; 
}