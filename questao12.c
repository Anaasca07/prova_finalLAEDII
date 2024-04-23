#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 2532
bool visitado[tam]; 
int matriz[tam][tam];


void lerGrafoInicial(int *linha,int *col){
    int i,j;
    FILE *arq =fopen("dados_matriz.txt","r");
    fscanf(arq,"%d %d",linha,col);
    for(i = 0; i < *linha; i++) {
        for(j = 0; j < *col; j++) {
            fscanf(arq, "%d", &matriz[i][j]);
        }
    }
    fclose(arq);
}

void inicializarVisitados(int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        visitado[i] = false;
    }
}

void dfs(int vertice, int tamanho) {
    visitado[vertice] = true;
    for (int i = 0; i < tamanho; i++) {
        if (matriz[vertice][i] == 1 && !visitado[i]) { 
            dfs(i, tamanho);
        }
    }
}

bool primeiroUltimoConectados(int tamanho) {
    inicializarVisitados(tamanho);
    dfs(0, tamanho);
    return visitado[tamanho - 1];
}

int main(){
    int tamanho;
    lerGrafoInicial(&tamanho, &tamanho);
    if (primeiroUltimoConectados(tamanho)) {
        printf("O primeiro e o ultimo vertice estao conectados.\n");
    } else {
        printf("O primeiro e o ultimo vertice NAO estao conectados.\n");
    }
    return 0;
}
