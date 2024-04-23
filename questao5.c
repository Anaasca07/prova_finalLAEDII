#include <stdio.h>
#include <stdlib.h>

#define tam 2532
int matriz[tam][tam];

void font(int n, int m, int matriz[tam][tam]){
    int i, aux[n],j;
    int fonte = 0;
    for(j=0;j<m;j++){
        aux[j] = 0;
        for(i=0;i<n;i++){
            aux[j] += matriz[i][j];
        }
        if(aux[j] == 0){
            printf("%d = vertice fonte\n",j);
            fonte = 1;
            return;
        }
    }
    printf("Nao tem vertice fonte.\n");
}



int main(){
    int linha,coluna;
    font(linha,coluna,matriz);
    return 0;
}