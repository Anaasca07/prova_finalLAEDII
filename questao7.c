#include <stdio.h>
#include <stdlib.h>

#define tam 2532
int matriz[tam][tam];

void grafoComplemetar(int linha, int coluna, int matriz[tam][tam]){
    FILE *arquivo = fopen("dados_grafo_complementar.txt", "w");
    fprintf(arquivo, "%d %d\n", linha, coluna);
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if (matriz[i][j] == 0){
                fprintf(arquivo, "%d ", 1);
            }else{
                fprintf(arquivo, "%d ", 0);
            }
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}

int main(){
    int linha,coluna;
    grafoComplemetar(linha,coluna,matriz);
    return 0;
}
