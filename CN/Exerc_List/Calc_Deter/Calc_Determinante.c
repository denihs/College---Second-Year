#include <stdio.h>
#include <stdlib.h>
#include "DinamicAlocation.h"

int validarEntrada();
int setTrianguloSuperior(float ** M, int x);
int trocarLinha(float ** M, int TAM, int n);
float calculoDeterminante(float ** M, int nTrocas, int TAM);
int main() {
    float **Matriz, determinante;
    int trocas;
    printf("Informe a dimensão da matriz->> ");
    int x = validarEntrada();
    if (x) {
        Matriz = Aloca(x,x);
        Matriz = preencher(Matriz, x,x);
        trocas = setTrianguloSuperior(Matriz, x);
        determinante = calculoDeterminante(Matriz, trocas, x);
        printf("\nMAtriz Final\n");
        exibir(Matriz, x,x);
        printf("\nDeterminante\n");
        printf("%.4f\n\n",determinante);
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

int setTrianguloSuperior(float ** M, int x) {
    int n_troca=0;
    float m, L;
    for (int pass = 0; pass < x - 1; pass++) {
        if (trocarLinha(M, x, pass)) { n_troca++; }
        for (int i = pass; i < x-1; i++) {
            m = (M[i + 1][pass] / M[pass][pass]) * -1;
            for (int j = pass; j < x; j++) {
                L = m * M[pass][j] + M[i + 1][j];
                M[i + 1][j] = L;
            }

        }
    }
    return n_troca;
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
float calculoDeterminante(float ** M, int nTrocas, int TAM) {
    float det=1;
    for (int i=0; i<TAM; i++) {
        det *= M[i][i];
    }
    return nTrocas % 2 == 0 ? det : det * -1;
}