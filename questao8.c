#include <stdio.h>
#include <stdlib.h>

#define tam 2532
int matriz[tam][tam];

void inverterGrafo(int n, const char *arquivoSaida) {
    FILE *arquivo = fopen(arquivoSaida, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para gravaçao.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == 1) {
                fprintf(arquivo, "%d %d\n", j, i); 
            }
        }
    }
    fclose(arquivo);
}

int main(){
    int linha;

    inverterGrafo(linha,"dados_grafos_invertido.txt");

    return 0;
}
