#include <stdio.h>
#include <stdlib.h>

#define tam 2532
int matriz[tam][tam];

void sumidouro(int n, int m, int matriz[][tam]){
    int i, aux[n], j;
    int temSumidouro = 0;
    for(i = 0; i < n; i++){
        aux[i] = 0;
        for(j = 0; j < m; j++){
            aux[i] += matriz[i][j];
        }
        if(aux[i] == 0){
            printf("%d = sumidouro\n", i);
            temSumidouro = 1;
            return;
        }
    }
    printf("Nao tem sumidouro.\n");
}

int main(){
    int linha = tam, coluna = tam;
    
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matriz[i][j] = 0;
        }
    }
    
    sumidouro(linha, coluna, matriz);
    return 0;
}
