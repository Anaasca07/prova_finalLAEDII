#include <stdio.h>
#include <stdlib.h>

#define tam 2532
int matriz[tam][tam];

void grauEmissao(int n) {
    FILE *arquivo = fopen("dados_grafos_emissao.txt", "w");
    for (int i = 0; i < n; i++) {
        int grauEmissao = 0;
        for (int j = 0; j < n; j++) {
            grauEmissao += matriz[i][j];
        }
        fprintf(arquivo, "%d %d\n", i, grauEmissao); 
    }
    fclose(arquivo);
}


void grauRecepcao(int n) {
    FILE *arquivo = fopen("dados_grafos_recepcao.txt", "w");
    for (int i = 0; i < n; i++) {
        int grauRecepcao = 0;
        for (int j = 0; j < n; j++) {
            grauRecepcao += matriz[j][i];
        }
        fprintf(arquivo, "%d %d\n", i, grauRecepcao); 
    }
    fclose(arquivo);
}

int main(){
    int linha;

    grauEmissao(linha);
    grauRecepcao(linha);

    return 0;
}