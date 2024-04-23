#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 2532
int matriz[tam][tam];

bool formaClique(int vertices[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (matriz[vertices[i]][vertices[j]] == 0) {
                return false;
            }
        }
    }
    return true;
}

void bronKerbosch(int* r, int* p, int* x, int rSize, int pSize, int xSize, int* maiorClique, int* tamanhoMaiorClique) {
    if (pSize == 0 && xSize == 0) {
        if (rSize > *tamanhoMaiorClique) {
            *tamanhoMaiorClique = rSize;
            for (int i = 0; i < rSize; i++) {
                maiorClique[i] = r[i];
            }
        }
        return;
    }

    for (int i = 0; i < pSize; i++) {
        int v = p[i];
        int* rNovo = (int*)malloc((rSize + 1) * sizeof(int));
        int* pNovo = (int*)malloc(pSize * sizeof(int));
        int* xNovo = (int*)malloc(xSize * sizeof(int));

        for (int j = 0; j < rSize; j++) {
            rNovo[j] = r[j];
        }
        rNovo[rSize] = v;

        int pNovoSize = 0;
        int xNovoSize = 0;

        for (int j = 0; j < pSize; j++) {
            if (matriz[v][p[j]] == 1) {
                pNovo[pNovoSize++] = p[j];
            }
        }

        for (int j = 0; j < xSize; j++) {
            if (matriz[v][x[j]] == 1) {
                xNovo[xNovoSize++] = x[j];
            }
        }

        bronKerbosch(rNovo, pNovo, xNovo, rSize + 1, pNovoSize, xNovoSize, maiorClique, tamanhoMaiorClique);

        free(rNovo);
        free(pNovo);
        free(xNovo);

        p[i] = p[pSize - 1];
        x[xSize++] = v;
        pSize--;
    }
}

void encontrarMaiorClique(int n) {
    int* maiorClique = (int*)malloc(n * sizeof(int));
    int tamanhoMaiorClique = 0;

    int* r = (int*)malloc(n * sizeof(int));
    int* p = (int*)malloc(n * sizeof(int));
    int* x = (int*)malloc(n * sizeof(int));

    int rSize = 0;
    int pSize = n;
    int xSize = 0;

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    bronKerbosch(r, p, x, rSize, pSize, xSize, maiorClique, &tamanhoMaiorClique);

    printf("O maior clique tem tamanho %d e inclui os vertices:\n", tamanhoMaiorClique);
    for (int i = 0; i < tamanhoMaiorClique; i++) {
        printf("%d ", maiorClique[i]);
    }
    printf("\n");

    free(maiorClique);
    free(r);
    free(p);
    free(x);
}

int main(){
    int linha;
    encontrarMaiorClique(linha);
    return 0;
}


