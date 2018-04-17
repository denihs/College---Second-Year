#include <stdio.h>
#include <stdlib.h>
#include "DinamicAlocation.h"

int validarEntrada();
void setTrianguloSuperior(float ** M, int x);
int trocarLinha(float ** M, int TAM, int n);

int main() {
    float **Matriz;
    printf("Informe a dimensão da matriz->> ");
    int x = validarEntrada();
    if (x) {
        Matriz = Aloca(x,x);
        Matriz = preencher(Matriz, x,x);
        printf("\nMAtriz Passada\n");
        exibir(Matriz, x,x);
        setTrianguloSuperior(Matriz, x);
        printf("\nMAtriz Final\n");
        exibir(Matriz, x,x);
    }
    Matriz = Liberacao(Matriz, x);
    return 0;
}

int validarEntrada(){
    int x;
    scanf("%d", &x);
    if(x < 2) {
        printf("\n\nError!!!!\n\n");
        return 0;
    }
    return x;
}

void setTrianguloSuperior(float ** M, int x) {
    float m, L;
    for (int pass = 0; pass < x - 1; pass++) {
        trocarLinha(M, x, pass);
        for (int i = pass; i < x-1; i++) {
            m = (M[i + 1][pass] / M[pass][pass]) * -1;
            for (int j = pass; j < x+1; j++) {
                L = m * M[pass][j] + M[i + 1][j];
                M[i + 1][j] = L;
            }

        }
    }
}
int trocarLinha(float ** M, int TAM, int n) {
    float v1, v2;
    float n1 = M[n][n] < 0 ? M[n][n] * -1 : M[n][n],
          n2 = M[n+1][n] < 0 ? M[n+1][n] * -1 : M[n+1][n];
    if(n1 < n2){
        for(int i=0; i < TAM; i++) {
            v1 = M[n][i];
            v2 = M[n + 1][i];
            M[n][i] = v2;
            M[n + 1][i] = v1;
        }
        return 1;
    }
    return 0;
}

void calculoX(float ** M, int TAM) {
    float x=1, aux=1, **vetAux = Aloca(1, TAM+1);
    for (int i=0; i< TAM; i++) {

    }
}