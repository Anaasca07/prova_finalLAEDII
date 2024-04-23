#include <stdio.h>
#include <stdlib.h>

#define tam 2532
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

void totalLinhaColuna(){
    int linha, col;
    lerGrafoInicial(&linha, &col);
    printf("total de linha = %d\ntotal de coluna = %d\n", linha, col);
}

void verticeMaiorGrau() {
    int i, j, max = -1, vertice = -1;
    int grau[tam] = {0};

    for(i = 0; i < tam; i++) {
        for(j = 0; j < tam; j++) {
            grau[i] += matriz[i][j];
        }
    }

    for(i = 0; i < tam; i++) {
        if(grau[i] > max) {
            max = grau[i];
            vertice = i;
        }
    }

    printf("O vertice de maior grau e %d com grau %d\n", vertice, max);
}

int main(){
    int linha, coluna;
    lerGrafoInicial(&linha,&coluna);
    totalLinhaColuna();
    verticeMaiorGrau();
    return 0;
}